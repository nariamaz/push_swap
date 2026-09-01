#!/bin/bash

EXECFILE=../push_swap

# Colors for scannable test results
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
RESET="\033[0m"

run_test_quoted()
{
    TESTCASE="$1"
    EXPECTED_ERR="$2"  # 1 if "Error\n" is expected on stderr, 0 if nothing expected

    echo -n "Test [Quoted] \"${TESTCASE}\": "

    # Capture stderr (fd 2) while silencing stdout (fd 1)
    STDERR_OUT=$(${EXECFILE} "${TESTCASE}" 2>&1 >/dev/null)

    if [ "${EXPECTED_ERR}" -eq 1 ]; then
        if [ "${STDERR_OUT}" == "Error" ]; then
            echo -e "${GREEN}PASS${RESET} (Printed Error to stderr)"
        else
            echo -e "${RED}FAIL${RESET} (Expected 'Error', got: '${STDERR_OUT}')"
        fi
    else
        if [ -z "${STDERR_OUT}" ]; then
            echo -e "${GREEN}PASS${RESET} (Silent / No error on stderr)"
        else
            echo -e "${RED}FAIL${RESET} (Expected silent, got: '${STDERR_OUT}')"
        fi
    fi
}

run_test_unquoted()
{
    TESTCASE="$1"
    EXPECTED_ERR="$2"

    echo -n "Test [Unquoted] ${TESTCASE}: "

    # Unquoted execution lets bash pass arguments as separate elements of argv
    STDERR_OUT=$(${EXECFILE} ${TESTCASE} 2>&1 >/dev/null)

    if [ "${EXPECTED_ERR}" -eq 1 ]; then
        if [ "${STDERR_OUT}" == "Error" ]; then
            echo -e "${GREEN}PASS${RESET} (Printed Error to stderr)"
        else
            echo -e "${RED}FAIL${RESET} (Expected 'Error', got: '${STDERR_OUT}')"
        fi
    else
        if [ -z "${STDERR_OUT}" ]; then
            echo -e "${GREEN}PASS${RESET} (Silent / No error on stderr)"
        else
            echo -e "${RED}FAIL${RESET} (Expected silent, got: '${STDERR_OUT}')"
        fi
    fi
}

echo "=========================================="
echo "      PUSH_SWAP BEHAVIOR MATRIX TESTS     "
echo "=========================================="

# 1. No arguments (argc < 2) -> Silent return 0
echo -n "Test [No Args] ./push_swap: "
STDERR_OUT=$(${EXECFILE} 2>&1 >/dev/null)
if [ -z "${STDERR_OUT}" ]; then
    echo -e "${GREEN}PASS${RESET} (Silent return 0)"
else
    echo -e "${RED}FAIL${RESET} (Expected silent, got: '${STDERR_OUT}')"
fi

# 2. Empty string (argc = 2) -> Error
run_test_quoted "" 1

# 3. Spaces-only string -> Error
run_test_quoted "   " 1

# 4. Single valid numbers -> Silent return 0
run_test_quoted "42" 0
run_test_quoted "+42" 0
run_test_quoted "-42" 0

# 5. Single invalid inputs / syntax errors -> Error
run_test_quoted "42a" 1
run_test_quoted "+" 1
run_test_quoted "-" 1
run_test_quoted "1 2-3 4" 1

# 6. Multiple valid numbers inside single string (argc = 2) -> Silent or Outputs Ops
run_test_quoted "1 2 3" 0
run_test_quoted "2 1 3 6 58" 0

# 7. Multiple valid numbers as separate arguments (argc > 2) -> Silent or Outputs Ops
run_test_unquoted "1 2 3" 0
run_test_unquoted "2 1 3 6 58" 0

# 8. Unquoted invalid cases -> Error
run_test_unquoted "1 2 a 4" 1
run_test_unquoted "1 + 2" 1

# 9. Single valid flags alone -> Error
run_test_quoted "--bench" 1
run_test_quoted "--simple" 1
run_test_quoted "--medium" 1
run_test_quoted "--complex" 1
run_test_quoted "--adaptive" 1

# 10. Invalid flag names -> Error
run_test_quoted "--random" 1
run_test_quoted "--" 1
run_test_quoted "-bench" 1          # single dash, not a valid flag prefix nor a number

# 11. Flag prefix collision (word-boundary check) -> Error
run_test_quoted "--BENCH42" 1       # "BENCH" matches as prefix, but next char isn't space/'\0'
run_test_quoted "--COMPLEXITY" 1    # "COMPLEX" matches as prefix, "ITY" breaks the boundary

# 12. Multiple valid flags together -> Silent return 0
run_test_quoted "--bench --simple" 1
run_test_quoted "--bench --simple --medium --complex --adaptive" 1

# 13. Duplicate flags -> Silent return 0 (counted twice, not an error per current design)
run_test_quoted "--bench --bench" 1

# 14. Flags combined with valid numbers -> Silent return 0
run_test_quoted "--bench 1 2 3" 0
run_test_quoted "1 --bench 2" 0
run_test_quoted "--simple --medium 5 -5 42" 1
run_test_quoted "--adaptive -2147483648 2147483647" 0

# 15. Flags combined with invalid numbers -> Error
run_test_quoted "--bench 5a" 1
run_test_quoted "--bench 1 2 a" 1
run_test_quoted "--bench ++5" 1

# 16. Integer boundary values (INT_MIN / INT_MAX) -> Silent return 0
run_test_quoted "2147483647" 0
run_test_quoted "-2147483648" 0

# 17. Integer overflow / underflow -> Error
run_test_quoted "2147483648" 1
run_test_quoted "-2147483649" 1
run_test_quoted "99999999999999" 1

# 18. Two-dash sequence not matching a known flag -> Error
run_test_quoted "--5" 1             # "--" triggers flag parsing, "5" isn't a valid flag name

# 19. Unquoted flags mixed with numbers (argc > 2) -> Silent return 0
run_test_unquoted "--bench 1 2 3" 0
run_test_unquoted "1 --simple 2 --medium 3" 1

# 20. Unquoted invalid flag + numbers -> Error
run_test_unquoted "--bench 1 2 x" 1
run_test_unquoted "--notaflag 1 2 3" 1

echo "=========================================="
