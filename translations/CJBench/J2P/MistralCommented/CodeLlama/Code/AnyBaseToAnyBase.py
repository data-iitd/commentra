
import sys

def main():
    n = sys.stdin.readline().strip()
    b1 = int(sys.stdin.readline().strip())
    b2 = int(sys.stdin.readline().strip())

    if not valid_for_base(n, b1):
        print("The number is invalid for this base!")
        return

    result = base2base(n, b1, b2)
    print("Converted number:", result)

def valid_for_base(n, base):
    valid_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    digits_for_base = valid_digits[:base]
    digits_list = set(digits_for_base)

    for char in n.upper():
        if char not in digits_list:
            return False

    return True

def base2base(n, b1, b2):
    decimal_value = 0
    output = ""

    for char_b1 in n.upper():
        if char_b1 >= "A" and char_b1 <= "Z":
            char_b2 = 10 + (ord(char_b1) - ord("A"))
        else:
            char_b2 = ord(char_b1) - ord("0")

        decimal_value = decimal_value * b1 + char_b2

    if decimal_value == 0:
        return "0"

    while decimal_value != 0:
        remainder = decimal_value % b2
        output = (chr(ord("0") + remainder) if remainder < 10 else chr(ord("A") + (remainder - 10))) + output
        decimal_value //= b2

    return output

if __name__ == "__main__":
    main()

