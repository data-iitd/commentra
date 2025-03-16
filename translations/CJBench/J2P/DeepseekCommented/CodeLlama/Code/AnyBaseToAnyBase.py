
import sys

def main():
    n = sys.stdin.readline().strip()
    b1 = int(sys.stdin.readline().strip())
    while b1 < 2 or b1 > 36:
        print("Invalid base! Please enter again.")
        b1 = int(sys.stdin.readline().strip())
    if not validForBase(n, b1):
        print("The number is invalid for this base!")
        return
    b2 = int(sys.stdin.readline().strip())
    while b2 < 2 or b2 > 36:
        print("Invalid base! Please enter again.")
        b2 = int(sys.stdin.readline().strip())
    result = base2base(n, b1, b2)
    print("Converted number: " + result)

def validForBase(n, base):
    validDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    digitsForBase = validDigits[:base]
    digitsList = set(digitsForBase)
    for charB1 in n.upper():
        if charB1 not in digitsList:
            return False
    return True

def base2base(n, b1, b2):
    decimalValue = 0
    output = ""
    for charB1 in n.upper():
        charB2 = ord(charB1) - ord('0') if charB1 >= '0' and charB1 <= '9' else ord(charB1) - ord('A') + 10
        decimalValue = decimalValue * b1 + charB2
    if decimalValue == 0:
        return "0"
    while decimalValue != 0:
        remainder = decimalValue % b2
        output = str(remainder if remainder < 10 else remainder - 10) + output
        decimalValue //= b2
    return output

if __name__ == "__main__":
    main()

