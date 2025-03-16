import random
import sys

class Main:
    def __init__(self, seed):
        self.random = random.Random(seed)

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

    def calculate_jacobi(self, a, num):
        if num <= 0 or num % 2 == 0:
            return 0
        a = a % num
        jacobi = 1
        while a != 0:
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
        return jacobi if num == 1 else 0

    def solovay_strassen(self, num, iterations):
        if num <= 1:
            return False
        if num <= 3:
            return True
        for _ in range(iterations):
            r = abs(self.random.randint(2, num - 2))
            a = r % (num - 1) + 1
            jacobi = (num + self.calculate_jacobi(a, num)) % num
            mod = self.calculate_modular_exponentiation(a, (num - 1) // 2, num)
            if jacobi == 0 or mod != jacobi:
                return False
        return True

def main():
    seed = 42
    random.seed(seed)
    try:
        num = int(input("Enter the number to check for primality: "))
        iterations = int(input("Enter the number of iterations: "))
        test = Main(seed)
        is_prime = test.solovay_strassen(num, iterations)
        print(f"{num} is {'probably prime.' if is_prime else 'composite.'}")
    except ValueError:
        print("Please enter a valid number and integer for iterations.")

if __name__ == "__main__":
    main()
