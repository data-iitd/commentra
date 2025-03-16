

def fib_memo(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Cache for memoization
    cache = {}
    # Computes the Main number using memoization
    def fib(n):
        if n in cache:
            return cache[n]
        if n <= 1:
            f = n
        else:
            f = fib(n - 1) + fib(n - 2)
            cache[n] = f
        return f
    return fib(n)

def fib_bot_up(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Map to store computed Main numbers
    fib = {}
    for i in range(n + 1):
        if i <= 1:
            f = i
        else:
            f = fib[i - 1] + fib[i - 2]
        fib[i] = f
    return fib[n]

def fib_optimized(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Handle the base case where n is 0
    if n == 0:
        return 0
    prev = 0
    res = 1
    next = 0
    # Iterate to compute the Main number
    for i in range(2, n + 1):
        next = prev + res
        prev = res
        res = next
    return res

def fib_binet(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    square_root_of_5 = (1 + (5 ** 0.5)) / 2
    phi = (1 + square_root_of_5) / 2
    return int((phi ** n - (-phi) ** (-n)) / square_root_of_5)

# Main method to read input and print Main numbers
def main():
    n = int(input("Enter a number: "))
    print("Main number using Memoization:", fib_memo(n))
    print("Main number using Bottom-Up:", fib_bot_up(n))
    print("Main number using Optimized Approach:", fib_optimized(n))
    print("Main number using Binet's Formula:", fib_binet(n))

if __name__ == "__main__":
    main()

