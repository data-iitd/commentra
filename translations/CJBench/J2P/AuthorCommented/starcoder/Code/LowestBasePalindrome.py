import sys

class Main:
    def __init__(self):
        pass

    def main(self):
        # Read the number to check
        number = int(sys.stdin.readline())

        # Find the lowest base in which the number is a palindrome
        base = self.lowestBasePalindrome(number)

        # Print the result
        print(base)

    def computeDigitsInBase(self, number, base):
        digits = []
        while number > 0:
            digits.append(number % base)
            number /= base
        return digits

    def isPalindromic(self, list):
        size = len(list)
        for i in range(0, size / 2):
            if not list[i] == list[size - 1 - i]:
                return False
        return True

    def isPalindromicInBase(self, number, base):
        if number <= 1:
            return True

        if number % base == 0:
            return False

        return self.isPalindromic(self.computeDigitsInBase(number, base))

    def lowestBasePalindrome(self, number):
        if number <= 1:
            return 2

        base = 2
        while not self.isPalindromicInBase(number, base):
            base += 1
        return base

# 