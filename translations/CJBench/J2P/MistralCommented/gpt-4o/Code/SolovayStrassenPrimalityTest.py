import random

class Main:
    def __init__(self, seed):
        # Initialize random number generator with given seed
        random.seed(seed)

    @staticmethod
    def calculate_modular_exponentiation(base, exponent, mod):
        # Helper method to calculate modular exponentiation
        x = 1
        y = base
        while exponent > 0:
            if exponent % 2 == 1:
                x = (x * y) % mod
            y = (y * y) % mod
            exponent //= 2
        return x % mod

    def calculate_jacobi(self, a, num):
        # Helper method to calculate Jacobi symbol
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
            a, num = num, a  # Swap a and num
            if a % 4 == 3 and num % 4 == 3:
                jacobi = -jacobi
            a = a % num
        return jacobi if num == 1 else 0

    def solovay_strassen(self, num, iterations):
        # Main method to check if a number is prime using Solovay-Strassen algorithm
        if num <= 1:
            return False
        if num <= 3:
            return True
        for _ in range(iterations):
            r = abs(random.randint(2, num - 1))
            a = r % (num - 1) + 1
            jacobi = (num + self.calculate_jacobi(a, num)) % num
            mod = self.calculate_modular_exponentiation(a, (num - 1) // 2, num)
            if jacobi == 0 or mod != jacobi:
                return False
        return True

if __name__ == "__main__":
    try:
        # Ask user for valid number to check for primality
        num = int(input("Enter the number to check for primality: "))
        
        # Ask user for valid integer for iterations
        iterations = int(input("Enter the number of iterations: "))
        
        # Initialize Main object with seed 42
        test = Main(42)

        # Check if the number is prime using Solovay-Strassen algorithm
        is_prime = test.solovay_strassen(num, iterations)

        # Print the result
        print(f"{num} is {'probably prime.' if is_prime else 'composite.'}")
    except ValueError as e:
        print(f"An error occurred: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

# <END-OF-CODE>
