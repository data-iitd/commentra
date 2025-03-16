
import random

class Main:
    # Initialize random number generator with given seed
    def __init__(self, seed):
        self.random = random.Random(seed)

    # Main method to start the program
    def main(self):
        try:
            # Ask user for valid number to check for primality
            while True:
                num = int(input("Enter the number to check for primality: "))
                if num > 0:
                    break
                print("Please enter a valid number.")

            # Ask user for valid integer for iterations
            while True:
                iterations = int(input("Enter the number of iterations: "))
                if iterations > 0:
                    break
                print("Please enter a valid integer for iterations.")

            # Initialize Main object with seed 42
            test = Main(42)

            # Check if the number is prime using Solovay-Strassen algorithm
            isPrime = test.solovayStrassen(num, iterations)

            # Print the result
            print(num, "is", "probably prime." if isPrime else "composite.")
        except Exception as e:
            # Handle exceptions
            print("An error occurred:", e)

    # Helper method to calculate modular exponentiation
    def calculateModularExponentiation(self, base, exponent, mod):
        x = 1
        y = base
        while exponent > 0:
            if exponent % 2 == 1:
                x = x * y % mod
            y = y * y % mod
            exponent //= 2
        return x % mod

    # Helper method to calculate Jacobi symbol
    def calculateJacobi(self, a, num):
        if num <= 0 or num % 2 == 0:
            return 0
        a = a % num
        jacobi = 1
        while a!= 0:
            while a % 2 == 0:
                a //= 2
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

    # Main method to check if a number is prime using Solovay-Strassen algorithm
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
    Main().main()

