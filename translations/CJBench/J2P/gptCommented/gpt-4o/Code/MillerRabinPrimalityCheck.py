import random

class Main:
    @staticmethod
    def main():
        # Read a long integer n from user input
        n = int(input("Enter a number: "))
        
        # Read an integer k from user input, which determines the accuracy of the Miller-Rabin test
        k = int(input("Enter the number of iterations for accuracy: "))
        
        # Perform the Miller-Rabin probabilistic primality test
        is_probably_prime = Main.miller_rabin(n, k)
        # Output the result of the probabilistic test
        print("Using Miller-Rabin Probabilistic Test: " + ("Probably Prime" if is_probably_prime else "Composite"))
        
        # Perform the deterministic Miller-Rabin primality test
        is_prime = Main.deterministic_miller_rabin(n)
        # Output the result of the deterministic test
        print("Using Deterministic Miller-Rabin Test: " + ("Prime" if is_prime else "Composite"))

    # Miller-Rabin probabilistic primality test
    @staticmethod
    def miller_rabin(n, k):
        # Handle small values of n
        if n < 4:
            return n == 2 or n == 3  # 2 and 3 are prime
        
        # Initialize variables for the test
        s = 0
        d = n - 1
        
        # Factor n-1 into 2^s * d
        while (d & 1) == 0:
            d >>= 1
            s += 1
        
        # Perform k iterations of the test
        for _ in range(k):
            # Choose a random base a in the range [2, n-2]
            a = random.randint(2, n - 2)
            # Check if n is composite with respect to base a
            if Main.check_composite(n, a, d, s):
                return False  # n is composite
        return True  # n is probably prime

    # Deterministic Miller-Rabin primality test for small values of n
    @staticmethod
    def deterministic_miller_rabin(n):
        # Handle values of n less than 2
        if n < 2:
            return False  # 0 and 1 are not prime
        
        # Initialize variables for the test
        r = 0
        d = n - 1
        
        # Factor n-1 into 2^r * d
        while (d & 1) == 0:
            d >>= 1
            r += 1
        
        # Test against a set of known small prime bases
        for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
            # If n is one of the small primes, return true
            if n == a:
                return True
            # Check if n is composite with respect to base a
            if Main.check_composite(n, a, d, r):
                return False  # n is composite
        return True  # n is prime

    # Check if n is composite given a base a, d, and s
    @staticmethod
    def check_composite(n, a, d, s):
        # Compute a^d mod n
        x = Main.power_mod_p(a, d, n)
        
        # Check if x is 1 or n-1
        if x == 1 or x == n - 1:
            return False  # n is not composite
        
        # Square x s-1 times and check for n-1
        for _ in range(1, s):
            x = Main.power_mod_p(x, 2, n)
            if x == n - 1:
                return False  # n is not composite
        return True  # n is composite

    # Modular exponentiation: computes (x^y) mod p
    @staticmethod
    def power_mod_p(x, y, p):
        res = 1  # Initialize result
        x %= p  # Update x if it is more than or equal to p
        
        # If x is 0, return 0
        if x == 0:
            return 0
        
        # Perform exponentiation by squaring
        while y > 0:
            # If y is odd, multiply x with result
            if (y & 1) == 1:
                res = Main.multiply_mod_p(res, x, p)
            y >>= 1  # Divide y by 2
            x = Main.multiply_mod_p(x, x, p)  # Square x
        return res  # Return the result

    # Modular multiplication: computes (a * b) mod p
    @staticmethod
    def multiply_mod_p(a, b, p):
        res = 0  # Initialize result
        a %= p  # Update a if it is more than or equal to p
        
        # Perform multiplication using the method of doubling
        while b > 0:
            # If b is odd, add a to result
            if (b & 1) == 1:
                res = (res + a) % p
            a = (2 * a) % p  # Double a
            b >>= 1  # Divide b by 2
        return res  # Return the result

# Run the main function
if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
