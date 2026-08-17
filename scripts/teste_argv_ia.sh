#!/bin/bash

EXECFILE=./push_swap

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

echo "=========================================="