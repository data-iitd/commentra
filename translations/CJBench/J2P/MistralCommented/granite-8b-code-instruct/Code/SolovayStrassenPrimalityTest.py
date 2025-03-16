

import random

class Main:
    # Initialize random number generator with given seed
    def __init__(self, seed):
        self.random = random.Random(seed)

    # Main method to start the program
    @staticmethod
    def main():
        num = int(input("Enter the number to check for primality: "))
        iterations = int(input("Enter the number of iterations: "))

        # Initialize Main object with seed 42
        test = Main(42)

        # Check if the number is prime using Solovay-Strassen algorithm
        is_prime = test.solovay_strassen(num, iterations)

        # Print the result
        print(f"{num} is {'probably' if is_prime else 'composite'} prime.")

    # Helper method to calculate modular exponentiation
    @staticmethod
    def calculate_modular_exponentiation(base, exponent, mod):
        x = 1
        y = base
        while exponent > 0:
            if exponent % 2 == 1:
                x = x * y % mod
            y = y * y % mod
            exponent //= 2
        return x % mod

    # Helper method to calculate Jacobi symbol
    def calculate_jacobi(self, a, num):
        if num <= 0 or num % 2 == 0:
            return 0
        a = a % num
        jacobi = 1
        while a!= 0:
            while a % 2 == 0:
                a //= 2
                n_mod_8 = num % 8
                if n_mod_8 == 3 or n_mod_8 == 5:
                    jacobi = -jacobi
            temp = a
            a = num
            num = temp
            if a % 4 == 3 and num % 4 == 3:
                jacobi = -jacobi
            a = a % num
        return (num == 1) and jacobi or 0

    # Main method to check if a number is prime using Solovay-Strassen algorithm
    def solovay_strassen(self, num, iterations):
        if num <= 1:
            return False
        if num <= 3:
            return True
        for i in range(iterations):
            r = abs(self.random.randint(1, num - 1)) + 2
            a = r % (num - 1) + 1
            jacobi = (num + self.calculate_jacobi(a, num)) % num
            mod = self.calculate_modular_exponentiation(a, (num - 1) // 2, num)
            if jacobi == 0 or mod!= jacobi:
                return False
        return True

if __name__ == "__main__":
    Main.main()

