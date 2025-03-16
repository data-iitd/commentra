
import sys
import string

MINIMUM_BASE = 2
MAXIMUM_BASE = 36

def main():
    n = sys.stdin.readline().strip()
    b1 = int(sys.stdin.readline().strip())
    while b1 < MINIMUM_BASE or b1 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        print("Enter beginning base: ")
        b1 = int(sys.stdin.readline().strip())
    if not validForBase(n, b1):
        print("The number is invalid for this base!")
        return
    b2 = int(sys.stdin.readline().strip())
    while b2 < MINIMUM_BASE or b2 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        print("Enter end base: ")
        b2 = int(sys.stdin.readline().strip())
    result = base2base(n, b1, b2)
    print("Converted number: " + result)

def validForBase(n, base):
    validDigits = string.digits + string.ascii_uppercase
    digitsForBase = validDigits[:base]
    digitsList = set(digitsForBase)
    for c in n.upper():
        if c not in digitsList:
            return False
    return True

def base2base(n, b1, b2):
    decimalValue = 0
    output = []
    for charB1 in n.upper():
        charB2 = ord(charB1) - ord('0') if charB1 in string.digits else ord(charB1) - ord('A') + 10
        decimalValue = decimalValue * b1 + charB2
    if decimalValue == 0:
        return "0"
    while decimalValue!= 0:
        remainder = decimalValue % b2
        output.insert(0, chr(remainder + ord('0') if remainder < 10 else remainder + ord('A') - 10))
        decimalValue /= b2
    return "".join(output)

if __name__ == "__main__":
    main()

