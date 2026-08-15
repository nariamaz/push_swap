push_swap/
├── Makefile                        # Mariana — wildcarded SRCS, rarely touched by anyone
├── README.md                       # Mariana drafts, Lyra adds the algorithm-justification section
├── .gitignore
│
├── include/
│   ├── push_swap.h                 # Joint, Day 1 — just #includes the headers below, stays ~empty
│   ├── types.h                     # Joint, Day 1 — t_stack, t_data — FROZEN after Day 1
│   ├── parse.h                     # Mariana
│   ├── stack.h                     # Mariana
│   ├── operations.h                # Mariana
│   ├── error.h                     # Mariana
│   ├── metrics.h                   # Mariana
│   ├── algo.h                      # Lyra
│   └── strategy.h                  # Lyra
│
├── lib_ft/
│   ├── Makefile
│   ├── libft.h
│   └── src/
│       ├── ft_atoi_strict.c        # strict signed-int parser, overflow-checked
│       ├── ft_split.c
│       ├── ft_strdup.c
│       ├── ft_strlen.c
│       ├── ft_isdigit.c
│       ├── ft_calloc.c
│       └── ft_putstr_fd.c
│
├── src/
│   ├── main.c                      # Joint — thin entry point only: argv -> parse_arguments -> strategy_run()
│   │
│   ├── parse/                      # Mariana
│   │   ├── parse_arguments.c
│   │   ├── is_valid.c
│   │   ├── has_duplicate.c
│   │   └── parse_flags.c           # --simple/--medium/--complex/--adaptive/--bench
│   │
│   ├── error/                      # Mariana
│   │   └── error.c                 # ft_error() -> "Error\n" + exit; malloc-fail cleanup path
│   │
│   ├── stack/                      # Mariana
│   │   ├── stack_new.c
│   │   ├── stack_add_back.c
│   │   ├── stack_size.c
│   │   ├── stack_free.c
│   │   └── get_rank.c              # normalize values -> 0..n-1
│   │
│   ├── init/                       # Mariana
│   │   └── init_push_swap.c        # parse + stack -> ready t_data, zeroes bench counters
│   │
│   ├── operations/                 # Mariana
│   │   ├── ops_swap.c              # sa, sb, ss
│   │   ├── ops_push.c              # pa, pb
│   │   ├── ops_rotate.c            # ra, rb, rr
│   │   └── ops_reverse_rotate.c    # rra, rrb, rrr
│   │
│   ├── metrics/                    # Mariana
│   │   ├── compute_disorder.c      # cast to double before dividing — see technical reference
│   │   ├── op_counter.c
│   │   └── benchmark.c             # --bench stderr output
│   │
│   ├── algorithms/
│   │   ├── common/                 # Lyra — cost engine ("Turk Sort")
│   │   │   ├── cost_engine.c
│   │   │   └── cost_utils.c
│   │   ├── simple/                 # Lyra — O(n²)
│   │   │   └── simple_sort.c
│   │   ├── medium/                 # Lyra — O(n√n)
│   │   │   ├── medium_sort.c
│   │   │   └── chunk_utils.c
│   │   └── complex/                # Lyra — O(n log n), radix
│   │       ├── complex_sort.c
│   │       └── radix_utils.c
│   │
│   └── strategy/                   # Lyra
│       ├── strategy_dispatch.c     # disorder thresholds + forced-strategy override logic
│       └── run.c                   # orchestration: disorder -> dispatch -> bench -> free (called from main)
│
└── bonus/                          # Mariana drafts, both polish — only pulled in by `make bonus`
    ├── checker.h
    ├── checker_main.c              # entry point, reads stack a the same way push_swap does
    ├── checker_parse.c             # reuses src/parse's validation rules — don't reinvent them
    └── checker_exec.c              # reads stdin instructions, executes them, prints OK/KO/Error

