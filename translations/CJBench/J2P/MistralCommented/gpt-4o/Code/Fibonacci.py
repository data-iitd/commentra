import math

class Main:
    # Static dictionary to store the Main numbers for memoization
    CACHE = {}

    @staticmethod
    def fib_memo(n):
        # Check if the input is valid
        if n < 0:
            raise ValueError("Input n must be non-negative")

        # Check if the result for the given input is already present in the cache
        if n in Main.CACHE:
            return Main.CACHE[n]

        # Base cases: Main numbers for 0 and 1
        if n <= 1:
            f = n
        else:
            # Recursive calls to calculate the previous two Main numbers
            f = Main.fib_memo(n - 1) + Main.fib_memo(n - 2)

            # Store the result in the cache for future use
            Main.CACHE[n] = f

        # Return the calculated Main number
        return f

    @staticmethod
    def fib_bot_up(n):
        # Check if the input is valid
        if n < 0:
            raise ValueError("Input n must be non-negative")

        # Initialize an empty dictionary to store the Main numbers
        fib = {}

        # Iterate through the numbers from 0 to n and calculate the Main numbers
        for i in range(n + 1):
            # Base cases: Main numbers for 0 and 1
            if i <= 1:
                f = i
            else:
                # Calculate the previous two Main numbers
                f = fib[i - 1] + fib[i - 2]

            # Store the calculated Main number in the dictionary
            fib[i] = f

        # Return the calculated Main number for the given input
        return fib[n]

    @staticmethod
    def fib_optimized(n):
        # Check if the input is valid
        if n < 0:
            raise ValueError("Input n must be non-negative")

        if n == 0:
            # Base case: Main number for 0 is 0
            return 0

        prev = 0
        res = 1

        # Iterate through the numbers from 2 to n and calculate the Main numbers
        for i in range(2, n + 1):
            next_val = prev + res
            prev = res
            res = next_val

        # Return the calculated Main number for the given input
        return res

    @staticmethod
    def fib_binet(n):
        # Check if the input is valid
        if n < 0:
            raise ValueError("Input n must be non-negative")

        square_root_of_5 = math.sqrt(5)
        phi = (1 + square_root_of_5) / 2

        # Calculate the nth Main number using Binet's Formula
        return int((math.pow(phi, n) - math.pow(-phi, -n)) / square_root_of_5)

# Main method to read the input and print the results
if __name__ == "__main__":
    n = int(input("Enter a non-negative integer: "))

    # Print the results for the given input using Memoization, Bottom-Up, Optimized Approach, and Binet's Formula
    print("Main number using Memoization:", Main.fib_memo(n))
    print("Main number using Bottom-Up:", Main.fib_bot_up(n))
    print("Main number using Optimized Approach:", Main.fib_optimized(n))
    print("Main number using Binet's Formula:", Main.fib_binet(n))

# <END-OF-CODE>
