def is_valid_for_base(n, base):
    valid_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    valid_digits_for_base = valid_digits[:base]
    return all(char in valid_digits_for_base for char in n.upper())

def base2base(n, b1, b2):
    decimal_value = 0
    output = ""

    # Convert the number from base b1 to decimal
    for char in n.upper():
        char_value = ord(char) - ord('0') if '0' <= char <= '9' else ord(char) - ord('A') + 10
        decimal_value = decimal_value * b1 + char_value

    # Handle the case where the number is zero
    if decimal_value == 0:
        return "0"

    # Convert the decimal value to the target base b2
    while decimal_value > 0:
        remainder = decimal_value % b2
        char_to_insert = chr(remainder + ord('0') if remainder < 10 else remainder - 10 + ord('A'))
        output = char_to_insert + output
        decimal_value //= b2

    return output

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = data[0]
    b1 = int(data[1])
    b2 = int(data[2])

    if not is_valid_for_base(n, b1):
        print("The number is invalid for this base!")
        return

    result = base2base(n, b1, b2)
    print("Converted number: " + result)

if __name__ == "__main__":
    main()
