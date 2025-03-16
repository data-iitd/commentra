
import sys

def main():
    n = input("Enter a number: ")
    b1 = int(input("Enter beginning base: "))
    while b1 < 2 or b1 > 36:
        print("Invalid base! Please enter again.")
        b1 = int(input("Enter beginning base: "))
    if not validForBase(n, b1):
        print("The number is invalid for this base!")
        return
    b2 = int(input("Enter end base: "))
    while b2 < 2 or b2 > 36:
        print("Invalid base! Please enter again.")
        b2 = int(input("Enter end base: "))
    result = base2base(n, b1, b2)
    print("Converted number: " + result)

def validForBase(n, base):
    validDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    digitsForBase = validDigits[:base]
    digitsList = set(digitsForBase)
    for char in n.upper():
        if char not in digitsList:
            return False
    return True

def base2base(n, b1, b2):
    decimalValue = 0
    output = ""
    for charB1 in n.upper():
        charB2 = ord(charB1) - ord('A') + 10 if charB1 >= 'A' and charB1 <= 'Z' else ord(charB1) - ord('0')
        decimalValue = decimalValue * b1 + charB2
    if decimalValue == 0:
        return "0"
    while decimalValue != 0:
        remainder = decimalValue % b2
        output = chr(ord('0') + remainder) + output if remainder < 10 else chr(ord('A') + remainder - 10) + output
        decimalValue //= b2
    return output

if __name__ == "__main__":
    main()

