

import sys

def valid_for_base(n, base):
    valid_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    digits_for_base = valid_digits[:base]
    digits_set = set(digits_for_base)
    for c in n.upper():
        if c not in digits_set:
            return False
    return True

def base2base(n, b1, b2):
    decimal_value = 0
    output = ""
    for char_b1 in n.upper():
        char_b2 = ord(char_b1) - 48 if char_b1.isdigit() else ord(char_b1) - 55
        decimal_value = decimal_value * b1 + char_b2
    if decimal_value == 0:
        return "0"
    while decimal_value!= 0:
        remainder = decimal_value % b2
        output = (chr(remainder + 48) if remainder < 10 else chr(remainder + 55)) + output
        decimal_value //= b2
    return output

if __name__ == "__main__":
    n, b1, b2 = input().split()
    b1 = int(b1)
    b2 = int(b2)
    if b1 < 2 or b1 > 36 or b2 < 2 or b2 > 36:
        print("Invalid base! Please enter again.")
        sys.exit(1)
    if not valid_for_base(n, b1):
        print("The number is invalid for this base!")
        sys.exit(1)
    result = base2base(n, b1, b2)
    print("Converted number:", result)

