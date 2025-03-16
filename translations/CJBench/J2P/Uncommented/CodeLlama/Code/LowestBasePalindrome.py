import sys

def main():
    number = int(sys.stdin.readline().strip())
    base = lowestBasePalindrome(number)
    print(base)

def lowestBasePalindrome(number):
    checkNumber(number)
    base = 2
    while not isPalindromicInBase(number, base):
        base += 1
    return base

def isPalindromicInBase(number, base):
    checkNumber(number)
    checkBase(base)
    if number <= 1:
        return True
    if number % base == 0:
        return False
    return isPalindromic(computeDigitsInBase(number, base))

def isPalindromic(list):
    size = len(list)
    for i in range(size // 2):
        if list[i] != list[size - 1 - i]:
            return False
    return True

def computeDigitsInBase(number, base):
    checkNumber(number)
    checkBase(base)
    digits = []
    while number > 0:
        digits.append(number % base)
        number //= base
    return digits

def checkBase(base):
    if base <= 1:
        raise ValueError("Base must be greater than 1.")

def checkNumber(number):
    if number < 0:
        raise ValueError("Number must be non-negative.")

if __name__ == "__main__":
    main()

