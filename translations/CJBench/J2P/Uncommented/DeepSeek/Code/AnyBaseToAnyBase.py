MINIMUM_BASE = 2
MAXIMUM_BASE = 36

def is_valid_for_base(n, base):
    valid_digits = [
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    ]
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

def main():
    n = input()
    b1 = int(input())
    while b1 < MINIMUM_BASE or b1 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        print("Enter beginning base: ", end="")
        b1 = int(input())
    
    if not is_valid_for_base(n, b1):
        print("The number is invalid for this base!")
        return
    
    b2 = int(input())
    while b2 < MINIMUM_BASE or b2 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        print("Enter end base: ", end="")
        b2 = int(input())
    
    result = base2base(n, b1, b2)
    print("Converted number: " + result)

if __name__ == "__main__":
    main()
