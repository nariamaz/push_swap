*This project has been created as part of the 42 curriculum by maridos-, hequeiro.*

# push_swap

## Description

`push_swap` sorts a stack of integers using two stacks (`a` and `b`) and a
restricted set of operations, aiming to produce the sorted stack `a` using as few
operations as possible.

| Instruction | Name | Description | Target |
| :--- | :--- | :--- | :--- |
| `sa` | Swap A | Swap the top 2 elements of Stack A | Stack A |
| `sb` | Swap B | Swap the top 2 elements of Stack B | Stack B |
| `ss` | Swap Both | Execute `sa` and `sb` simultaneously | Both |
| `pa` | Push A | Move top element from Stack B to top of Stack A | Stack A |
| `pb` | Push B | Move top element from Stack A to top of Stack B | Stack B |
| `ra` | Rotate A | Shift all elements up by 1 (top becomes bottom) | Stack A |
| `rb` | Rotate B | Shift all elements up by 1 (top becomes bottom) | Stack B |
| `rr` | Rotate Both | Execute `ra` and `rb` simultaneously | Both |
| `rra` | Reverse Rotate A | Shift all elements down by 1 (bottom becomes top) | Stack A |
| `rrb` | Reverse Rotate B | Shift all elements down by 1 (bottom becomes top) | Stack B |
| `rrr` | Reverse Rotate Both | Execute `rra` and `rrb` simultaneously | Both |

The program embeds four sorting strategies — three fixed-complexity
algorithms and one adaptive dispatcher that picks between them based on how
disordered the input is — and an optional benchmark mode that reports the
metrics behind each run.

## Program Flow

```
main
 ├─ ft_validate_args(argc, argv, &data)                                           [src/parse/dispatcher.c]
 │   └─ per argv[i]:
 │        ├─ ft_is_blank(argv[i])
 │        │  → rejects empty / whitespace-only tokens
 │        │
 │        ├─ ft_parsing(argv[i], &data)
 │        │    ├─ ft_validate_flag(token, &data)                                  [src/parse/flags.c]
 │        │    │  → matches --bench/--simple/--medium/--complex/--adaptive,
 │        │    │    increments data.f_counter[]
 │        │    │
 │        │    └─ ft_validate_number(&token, &data)                               [src/parse/numbers.c]
 │        │           └─ ft_check_overflow(start, digits, is_negative)
 │        │               → digit-count + lexicographic comparison
 │        │                 against INT_MAX/MIN, increments data.total_nbs
 │        │
 │        └─ ft_has_number(argv[i])
 │           → tracked across the loop; if no digit at all, error
 │
 │
 ├─ ft_check_duplicate_f(&data)                                                   [src/parse/flags.c]
 │  → rejects repeated flags and more than one of simple/medium/complex/adaptive
 │
 ├─ ft_fill_stack(argc, argv, &stack_a)                                           [src/parse/numbers.c]
 │        → second pass over argv (flags skipped, already handled above)
 │        │
 │        ├─ ft_atoi(&token)
 │        │  → converts the now-validated token (no overflow risk at this point)
 │        │
 │        ├─ check_duplicate_n(stack_a, value)                                    [src/stack/stack_check.c]
 │        │  → aborts + clean_list on a repeated value
 │        │
 │        └─ add_to_list(&stack_a, value)                                         [src/stack/stack_add.c]
 │           → appends into the circular doubly linked list
 │
 ├─ stacks.a = stack_a; stacks.b = NULL
 ├─ ft_assign_index(stacks.a, data.total_nbs)                                     [src/algorithms/common/utils.c]
 │  → assigns each node a rank 0..n-1 by relative value
 │
 ├─ ft_compute_disorder(stacks.a, &data)                                          [src/metrics/strategy.c]
 │        → writes data.disorder directly, BEFORE any move, as required
 │
 ├─ ft_get_strategy(&data, &stacks)                                               [src/metrics/strategy.c]
 │    ├─ --simple / --medium / --complex given
 │    │ → forces the matching ft_sort_* directly, regardless of size or disorder
 │    │
 │    ├─ no flag / --adaptive AND total_nbs small → ft_sort_small(&stacks,&data)
 │    │
 │    └─ no flag / --adaptive, otherwise → ft_adaptive_strategy(...)
 │           └─ picks by disorder threshold, then calls the matching ft_sort_*
 │
 │
 ├─ ft_sort_small / ft_sort_simple / ft_sort_medium / ft_sort_complex
 │    └─ every move goes through ft_do_op(op, &stacks, &data)
 │           ├─ executes the operation (src/operations/*) on stacks->a /stacks->b
 │           │
 │           ├─ increments data.op_counter[op]
 │           └─ writes the operation name + '\n' to stdout
 │
 └─ if --bench: ft_show_benchmark(data) / ft_print_counts(data)
                [src/metrics/benchmark.c]
                → disorder %, strategy name + complexity class,
                  ft_total_ops(data), per-operation counts
```

## Algorithms

The subject requires the complexity class of a strategy to reflect the
number of Push_swap operations generated, not the Big-O of the underlying
C code. The arguments below are given in those terms.

### Simple — O(n²) — minimum extraction

For each of the `n` elements still in `a`: scan the remaining part of the
stack to find the position of the current minimum, rotate it to the top by
the shorter path (`ra` or `rra`, whichever needs fewer moves), then `pb` it.
Because the minimum is always pushed first, it ends at the bottom of `b`
and is the last one pushed back with `pa`, landing on top of `a` — giving
ascending order.

**Complexity argument:** each of the `n` extractions scans up to `n`
remaining elements and rotates up to `n/2` positions, giving O(n) work per
extraction and O(n²) overall — within the required class.

### Medium — O(n√n) — chunk sort

`ft_assign_index` gives every element a rank in `[0, n-1]`. The rank range
is split into `√n` chunks of size `√n` (computed with `ft_sqrt`, since
`math.h` is not an allowed external function).

**Phase 1 — distribute:** for each chunk, in ascending order, scan what
remains in `a`; elements whose rank falls in the current chunk are pushed
to `b`, everything else is rotated past (`ra`). This is `√n` passes, each
touching up to `n` elements: O(n√n).

**Phase 2 — merge:** repeatedly find the largest rank still in `b`,
rotate it to the top (`rb`/`rrb`, shorter path), and `pa` it. Because
Phase 1 pushed low-chunk elements first, `b` is already grouped by chunk
from bottom to top, so the largest-remaining search and rotation in Phase 2
stay bounded within chunk-sized windows rather than the whole of `b`,
keeping the aggregate cost at O(n√n).

**Design note:** this bound requires stack `b` to already be in ascending
order *within* each chunk by the time Phase 2 starts, which in turn
requires an `rb` immediately after any `pb` whose element's rank sits in
the lower half of its chunk during Phase 1.

### Complex — O(n log n) — LSD radix sort (binary)

Ranks are already non-negative integers in `[0, n-1]` (from
`ft_assign_index`), so no offset is needed for negative source values.

For each bit position `i`, from least to most significant, up to
`ft_bits_needed(n)` bits (`⌊log₂(n-1)⌋ + 1`): examine the top of `a`; if
bit `i` of its rank is `1`, move it to `b`, otherwise rotate it (`ra`).
After examining all `n` elements for that bit, push everything back from
`b` to `a` with `pa`. This preserves relative order within each bit group
(stability), the same property that makes classical LSD radix sort work.

**Complexity argument:** each of the `⌈log₂ n⌉` passes touches every
element once — O(n) per pass — giving O(n log n) overall, which is where
the "log n" in the required class comes from directly.

### Adaptive — dispatches to one of the above by disorder

| Disorder range | Strategy used | Complexity |
|---|---|---|
| `disorder < 0.2` | Simple | O(n²) |
| `0.2 ≤ disorder < 0.5` | Medium | O(n√n) |
| `disorder ≥ 0.5` | Complex | O(n log n) |

**Rationale for these thresholds:** they match the subject's required
regimes exactly (VI.3.3.4). Below the reasoning for why the boundaries
make sense operationally, not just as a fixed requirement: a nearly-sorted
stack (low disorder) needs very few corrective moves, so the simpler,
lower-overhead O(n²) minimum-extraction algorithm finishes in few
operations despite its worse asymptotic class — its constant factors are
small and it needs no setup (no rank assignment pass, no chunking). As
disorder grows, the number of out-of-place elements grows with it, and the
extra setup cost of chunking or bit-decomposition starts paying for itself
by avoiding the O(n²) blow-up a fully randomized input would cause under
the simple strategy.

This is the default behavior when no strategy flag is given, and is also
what `--adaptive` forces explicitly.

### Small-input shortcut — `ft_sort_small`

For very small stacks, none of the three general algorithms is worth its
setup cost (rank assignment, chunk sizing, bit-pass counting) — a stack of
2 or 3 elements has so few possible arrangements that the optimal sequence
of operations can simply be hardcoded:

- `n = 0` or `n = 1`: already sorted, no operations needed.
- `n = 2`: `sa` if the top two are out of order, nothing otherwise.
- `n = 3`: at most 2 operations suffice for any of the 6 possible
  arrangements (`sa`, `ra`, `rra`, or a short combination), so a fixed
  decision table handles every case without going through `ft_find_min`,
  chunking, or bit-decomposition logic at all.

**Where it fits in dispatch, and why:** the subject requires that an
explicit strategy flag "should work regardless of input size or disorder"
(VI.5), so `--simple`, `--medium`, and `--complex` must still run their
full general algorithm even on a 2- or 3-element stack — never silently
substituted by the shortcut. `ft_sort_small` is therefore only reachable
on the **adaptive** path (`--adaptive`, or no flag at all): `ft_get_strategy`
checks `data.total_nbs` against the small-input threshold *before* falling
through to `ft_adaptive_strategy`'s disorder-based dispatch, and only takes
the shortcut there.

## Disorder Metric

`disorder` is computed once, before any operation, as
`mistakes / total_pairs`, where a mistake is a pair `(i, j)` with `i`
appearing before `j` in the stack but holding a greater value.

## Instructions

### Compilation

```bash
make            # builds push_swap
make clean      # removes object files
make fclean     # removes object files and binaries
make re         # fclean + all
```

### Execution

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```

- Numbers may be passed as separate arguments or as one quoted,
  space-separated argument (or a mix of both).
- Omitting a strategy flag defaults to `--adaptive`.
- `--bench` sends metrics to `stderr`; the operation list stays on `stdout`.
- No arguments → the program exits silently.
- Invalid input (non-integer, out-of-range, duplicate values) → `Error`
  on `stderr`.

## Usage Examples

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
...

$> ./push_swap --simple 5 4 3 2 1 | wc -l
14

$> ./push_swap --complex "4 67 3 87 23" | ./checker "4 67 3 87 23"
OK

$> ./push_swap --bench --adaptive $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt)
OK
$> cat bench.txt
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0
```

## Contributions

| Learner | Areas |
|---|---|
| `<maridos->` | *(parsing, flag validation, benchmark mode, sorting algorithms)* |
| `<hequeiro>` | *(handling nodes operations, stack construction)* |

Both learners contributed to and can explain every part of the codebase,
per the group project requirements (VI.1).

## Resources

### References

- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [42 Norminette documentation](https://github.com/42School/norminette)

### AI usage disclosure

An AI assistant (Claude) was used throughout development, always with the
output reviewed, tested, and explained by both learners before being kept
— never copy-pasted without understanding, per the project's AI
Instructions.

- **Algorithm design and derivation**: working through why LSD radix sort
  in base 2 fits a two-stack model (2 destinations per pass matches
  exactly 2 stacks), deriving the number of required bit-passes from
  `⌊log₂(n-1)⌋ + 1` instead of a fixed 32, and deriving the optimal chunk
  count for chunk sort (`√n`) by minimizing the combined cost of the
  distribute and merge phases via calculus.
- **C language and pointer concepts**: clarifying pointer vs. pointee,
  single vs. double indirection (`char *` vs `char **`, `t_stack *` vs
  `t_stack **`), when a function needs a caller's pointer to survive past
  return, struct member access through `->` vs `.`, and static vs. const
  vs. global semantics under the "no global variables" constraint.
- **Testing**: generating a bash test harness for `--simple` with an
  embedded Python stack simulator to verify correctness without depending
  on the bonus `checker` being finished yet.

All generated code was reviewed line-by-line, tested against the cases
above, and both learners can explain the reasoning behind every algorithm
and pointer-handling decision in this repository.
