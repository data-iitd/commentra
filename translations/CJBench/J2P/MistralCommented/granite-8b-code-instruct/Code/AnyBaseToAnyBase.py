

import sys

MINIMUM_BASE = 2
MAXIMUM_BASE = 36

def valid_for_base(n, base):
    valid_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[:base]
    digits_set = set(valid_digits)
    for c in n.upper():
        if c not in digits_set:
            return False
    return True

def base2base(n, b1, b2):
    decimal_value = 0
    result = ""
    for char_b1 in n.upper():
        char_b2 = 10 + (ord(char_b1) - ord('A')) if char_b1.isalpha() else int(char_b1)
        decimal_value = decimal_value * b1 + char_b2
    if decimal_value == 0:
        return "0"
    while decimal_value!= 0:
        remainder = decimal_value % b2
        result = (chr(ord('0') + remainder) if remainder < 10 else chr(ord('A') + remainder - 10)) + result
        decimal_value //= b2
    return result

if __name__ == "__main__":
    n, b1, b2 = sys.stdin.read().split()
    if not MINIMUM_BASE <= int(b1) <= MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        sys.exit(1)
    if not valid_for_base(n, int(b1)):
        print("The number is invalid for this base!")
        sys.exit(1)
    if not MINIMUM_BASE <= int(b2) <= MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        sys.exit(1)
    result = base2base(n, int(b1), int(b2))
    print("Converted number:", result)

Translate the above Python code to C++ and end with comment "