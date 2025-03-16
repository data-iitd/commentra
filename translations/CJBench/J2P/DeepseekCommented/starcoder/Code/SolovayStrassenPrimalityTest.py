import random
import sys

class Main:
    def __init__(self, seed):
        self.random = random.Random(seed)

    def main(self):
        try:
            while True:
                num = int(input("Enter the number to check for primality: "))
                if num < 0:
                    raise ValueError("Number must be positive")
                iterations = int(input("Enter the number of iterations: "))
                if iterations < 0:
                    raise ValueError("Number of iterations must be positive")
                test = Main(42)
                isPrime = test.solovayStrassen(num, iterations)
                print(num, "is", "probably prime." if isPrime else "composite.")
        except ValueError as e:
            print("An error occurred:", e)
        except Exception as e:
            print("An error occurred:", e)

    def calculateModularExponentiation(self, base, exponent, mod):
        x = 1
        y = base
        while exponent > 0:
            if exponent % 2 == 1:
                x = x * y % mod
            y = y * y % mod
            exponent /= 2
        return x % mod

    def calculateJacobi(self, a, num):
        if num <= 0 or num % 2 == 0:
            return 0
        a = a % num
        jacobi = 1
        while a!= 0:
            while a % 2 == 0:
                a /= 2
                nMod8 = num % 8
                if nMod8 == 3 or nMod8 == 5:
                    jacobi = -jacobi
            temp = a
            a = num
            num = temp
            if a % 4 == 3 and num % 4 == 3:
                jacobi = -jacobi
            a = a % num
        return (num == 1) and jacobi or 0

    def solovayStrassen(self, num, iterations):
        if num <= 1:
            return False
        if num <= 3:
            return True
        for i in range(iterations):
            r = abs(self.random.randint(0, num - 1)) + 2
            a = r % (num - 1) + 1
            jacobi = (num + self.calculateJacobi(a, num)) % num
            mod = self.calculateModularExponentiation(a, (num - 1) // 2, num)
            if jacobi == 0 or mod!= jacobi:
                return False
        return True

if __name__ == "__main__":
    main = Main(42)
    main.main()

