import math

class Main:
    # Cache to store previously computed Main numbers for memoization
    CACHE = {}

    @staticmethod
    def fib_memo(n):
        # Validate input to ensure it is non-negative
        if n < 0:
            raise ValueError("Input n must be non-negative")
        # Check if the result is already cached
        if n in Main.CACHE:
            return Main.CACHE[n]
        # Base cases for Main sequence
        if n <= 1:
            f = n
        else:
            # Recursive calls to compute Main number
            f = Main.fib_memo(n - 1) + Main.fib_memo(n - 2)
            # Store the computed result in the cache
            Main.CACHE[n] = f
        return f

    @staticmethod
    def fib_bot_up(n):
        # Validate input to ensure it is non-negative
        if n < 0:
            raise ValueError("Input n must be non-negative")
        # Map to store Main numbers computed in a bottom-up manner
        fib = {}
        # Iteratively compute Main numbers from 0 to n
        for i in range(n + 1):
            # Base cases for Main sequence
            if i <= 1:
                f = i
            else:
                # Use previously computed values to calculate the current Main number
                f = fib[i - 1] + fib[i - 2]
            # Store the computed Main number in the map
            fib[i] = f
        # Return the Main number for n
        return fib[n]

    @staticmethod
    def fib_optimized(n):
        # Validate input to ensure it is non-negative
        if n < 0:
            raise ValueError("Input n must be non-negative")
        # Handle the base case for Main sequence
        if n == 0:
            return 0
        # Variables to store the last two Main numbers
        prev, res = 0, 1
        # Iteratively compute Main numbers up to n
        for i in range(2, n + 1):
            next_val = prev + res  # Calculate the next Main number
            prev = res              # Update previous Main number
            res = next_val          # Update current Main number
        # Return the Main number for n
        return res

    @staticmethod
    def fib_binet(n):
        # Validate input to ensure it is non-negative
        if n < 0:
            raise ValueError("Input n must be non-negative")
        # Calculate the golden ratio and its square root
        square_root_of_5 = math.sqrt(5)
        phi = (1 + square_root_of_5) / 2
        # Use Binet's formula to compute the Main number
        return int((math.pow(phi, n) - math.pow(-phi, -n)) / square_root_of_5)

# Main execution
if __name__ == "__main__":
    # Read the integer input for which Main number is to be computed
    n = int(input())
    # Print the Main number computed using different methods
    print("Main number using Memoization:", Main.fib_memo(n))
    print("Main number using Bottom-Up:", Main.fib_bot_up(n))
    print("Main number using Optimized Approach:", Main.fib_optimized(n))
    print("Main number using Binet's Formula:", Main.fib_binet(n))

# <END-OF-CODE>
