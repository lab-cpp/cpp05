#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
NC='\033[0m'

BINARY="./form"
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
        FAIL=$((FAIL + 1))
    fi
}

echo -e "\n${BOLD}══════════════════════════════════════════${NC}"
echo -e "${BOLD}  Testing ex01: Form up, maggots!${NC}"
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

make re > /dev/null 2>&1
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Build failed – cannot run tests.${NC}"
    exit 1
fi

ACTUAL=$($BINARY 2>&1)

assert_contains "Form Creation High Exception" "Form grade is too high" "$ACTUAL"
assert_contains "Form Creation Low Exception" "Form grade is too low" "$ACTUAL"
assert_contains "Successful Sign Message" "CEO signed Tax Form" "$ACTUAL"
assert_contains "Failed Sign Message" "Intern couldn't sign NDA because Form grade is too low." "$ACTUAL"
assert_contains "Form state print" "Status: Signed" "$ACTUAL"

if command -v valgrind > /dev/null; then
    valgrind --leak-check=full --error-exitcode=42 $BINARY > /dev/null 2>&1
    if [ $? -eq 42 ]; then
        echo -e "${RED}[KO]${NC} Valgrind: Memory leaks detected!"
        FAIL=$((FAIL + 1))
    else
        echo -e "${GREEN}[OK]${NC} Valgrind: No memory leaks"
        PASS=$((PASS + 1))
    fi
fi

echo -e "\n${BOLD}══════════════════════════════════════════${NC}"
TOTAL=$((PASS + FAIL))
if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  ✔ $PASS/$TOTAL tests passed${NC}"
else
    echo -e "${RED}${BOLD}  ✘ $FAIL/$TOTAL tests FAILED${NC}"
fi
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

[ "$FAIL" -eq 0 ]