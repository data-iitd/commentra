import sys

MINIMUM_BASE = 2
MAXIMUM_BASE = 36

def valid_for_base(n, base):
    valid_digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    digits_for_base = valid_digits[:base]
    digits_set = set(digits_for_base)
    
    for char in n.upper():
        if char not in digits_set:
            return False
    return True

def base_to_base(n, b1, b2):
    decimal_value = 0
    output = []
    
    for char_b1 in n.upper():
        char_b2 = 10 + (ord(char_b1) - ord('A')) if 'A' <= char_b1 <= 'Z' else ord(char_b1) - ord('0')
        decimal_value = decimal_value * b1 + char_b2
    
    if decimal_value == 0:
        return "0"
    
    while decimal_value != 0:
        remainder = decimal_value % b2
        output.insert(0, chr(remainder + ord('0')) if remainder < 10 else chr(remainder - 10 + ord('A')))
        decimal_value //= b2
    
    return ''.join(output)

def main():
    n = input()
    b1 = int(input())
    
    while b1 < MINIMUM_BASE or b1 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        print("Enter beginning base: ", end="")
        b1 = int(input())
    
    if not valid_for_base(n, b1):
        print("The number is invalid for this base!")
        return
    
    b2 = int(input())
    
    while b2 < MINIMUM_BASE or b2 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        print("Enter end base: ", end="")
        b2 = int(input())
    
    result = base_to_base(n, b1, b2)
    print("Converted number:", result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
