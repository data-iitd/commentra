import math

class Fibonacci:
    CACHE = {}

    @staticmethod
    def fib_memo(n):
        if n < 0:
            raise ValueError("Input n must be non-negative")
        if n in Fibonacci.CACHE:
            return Fibonacci.CACHE[n]

        if n <= 1:
            f = n
        else:
            f = Fibonacci.fib_memo(n - 1) + Fibonacci.fib_memo(n - 2)
            Fibonacci.CACHE[n] = f
        return f

    @staticmethod
    def fib_bot_up(n):
        if n < 0:
            raise ValueError("Input n must be non-negative")
        fib = {}

        for i in range(n + 1):
            if i <= 1:
                f = i
            else:
                f = fib[i - 1] + fib[i - 2]
            fib[i] = f

        return fib[n]

    @staticmethod
    def fib_optimized(n):
        if n < 0:
            raise ValueError("Input n must be non-negative")
        if n == 0:
            return 0
        prev, res = 0, 1
        for i in range(2, n + 1):
            next_fib = prev + res
            prev = res
            res = next_fib
        return res

    @staticmethod
    def fib_binet(n):
        if n < 0:
            raise ValueError("Input n must be non-negative")
        square_root_of_5 = math.sqrt(5)
        phi = (1 + square_root_of_5) / 2
        return int((math.pow(phi, n) - math.pow(-phi, -n)) / square_root_of_5)

if __name__ == "__main__":
    n = int(input("Enter a non-negative integer: "))

    print("Fibonacci number using Memoization:", Fibonacci.fib_memo(n))
    print("Fibonacci number using Bottom-Up:", Fibonacci.fib_bot_up(n))
    print("Fibonacci number using Optimized Approach:", Fibonacci.fib_optimized(n))
    print("Fibonacci number using Binet's Formula:", Fibonacci.fib_binet(n))

# <END-OF-CODE>
