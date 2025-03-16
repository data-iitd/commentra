def valid_for_base(n, base):
    valid_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    digits_for_base = valid_digits[:base]
    digits_list = set(digits_for_base)

    for c in n.upper():
        if c not in digits_list:
            return False
    return True

def base2base(n, b1, b2):
    decimal_value = 0
    output = ""

    for char_b1 in n.upper():
        char_b2 = ord(char_b1) - ord('0') if '0' <= char_b1 <= '9' else ord(char_b1) - ord('A') + 10
        decimal_value = decimal_value * b1 + char_b2

    if decimal_value == 0:
        return "0"

    while decimal_value != 0:
        remainder = decimal_value % b2
        output = (chr(remainder + ord('0') if remainder < 10 else remainder - 10 + ord('A')) + output)
        decimal_value //= b2

    return output

# Main program
if __name__ == "__main__":
    import sys
    input = sys.stdin.readline

    n = input().strip()
    b1 = int(input().strip())
    while b1 < 2 or b1 > 36:
        print("Invalid base! Please enter again.")
        print("Enter beginning base: ", end="")
        b1 = int(input().strip())

    if not valid_for_base(n, b1):
        print("The number is invalid for this base!")
        exit()

    b2 = int(input().strip())
    while b2 < 2 or b2 > 36:
        print("Invalid base! Please enter again.")
        print("Enter end base: ", end="")
        b2 = int(input().strip())

    result = base2base(n, b1, b2)
    print("Converted number: " + result)
