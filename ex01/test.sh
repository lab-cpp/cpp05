#!/bin/bash
# ─────────────────────────────────────────────────────────────────────────────
# test.sh – Functional tests for ex00
# ─────────────────────────────────────────────────────────────────────────────

GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
NC='\033[0m'

BINARY="./bureaucrat"

PASS=0
FAIL=0

assert_contains() {
    local description="$1"
    local needle="$2"
    local haystack="$3"

    if echo "$haystack" | grep -qF "$needle"; then
        echo -e "${GREEN}[OK]${NC} $description"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}[KO]${NC} $description"
        echo -e "   ${BOLD}Expected to contain:${NC} $needle"
        echo -e "   ${BOLD}Got:${NC} $haystack"
        FAIL=$((FAIL + 1))
    fi
}

assert_exit_code() {
    local description="$1"
    local expected_code="$2"
    local actual_code="$3"

    if [ "$actual_code" -eq "$expected_code" ]; then
        echo -e "${GREEN}[OK]${NC} $description"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}[KO]${NC} $description"
        echo -e "   ${BOLD}Expected exit code:${NC} $expected_code"
        echo -e "   ${BOLD}Got:${NC} $actual_code"
        FAIL=$((FAIL + 1))
    fi
}

echo -e "\n${BOLD}══════════════════════════════════════════${NC}"
echo -e "${BOLD}  Testing ex00: Bureaucrat${NC}"
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

make re > /dev/null 2>&1
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Build failed – cannot run tests.${NC}"
    exit 1
fi

# Run the program and capture output (both stdout and stderr)
ACTUAL=$($BINARY 2>&1)

# 1. Output tests
assert_contains "Valid output overload" "Hermes, bureaucrat grade 34." "$ACTUAL"
assert_contains "Creation Too High Exception" "Grade is too high" "$ACTUAL"
assert_contains "Creation Too Low Exception" "Grade is too low" "$ACTUAL"
assert_contains "Increment Too High Exception" "Grade is too high" "$ACTUAL"
assert_contains "Decrement Too Low Exception" "Grade is too low" "$ACTUAL"

# 2. Leak test (Valgrind smoke test)
if command -v valgrind > /dev/null; then
    valgrind --leak-check=full --error-exitcode=42 $BINARY > /dev/null 2>&1
    EXIT_CODE=$?
    if [ "$EXIT_CODE" -eq 42 ]; then
        echo -e "${RED}[KO]${NC} Valgrind: Memory leaks detected!"
        FAIL=$((FAIL + 1))
    else
        echo -e "${GREEN}[OK]${NC} Valgrind: No memory leaks"
        PASS=$((PASS + 1))
    fi
else
    echo -e "${YELLOW}Valgrind not installed, skipping leak test.${NC}"
fi

echo -e "\n${BOLD}══════════════════════════════════════════${NC}"
TOTAL=$((PASS + FAIL))
if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  ✔ $PASS/$TOTAL tests passed${NC}"
else
    echo -e "${RED}${BOLD}  ✘ $FAIL/$TOTAL tests FAILED${NC}"
fi
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

# Enforce CI strictness
[ "$FAIL" -eq 0 ]