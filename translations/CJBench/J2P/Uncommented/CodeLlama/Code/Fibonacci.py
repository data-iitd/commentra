
import math
def fib_memo(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    cache = {0: 0, 1: 1}
    if n in cache:
        return cache[n]
    if n <= 1:
        return n
    else:
        f = fib_memo(n - 1) + fib_memo(n - 2)
        cache[n] = f
        return f
def fib_bot_up(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    fib = {0: 0, 1: 1}
    for i in range(2, n + 1):
        f = fib[i - 1] + fib[i - 2]
        fib[i] = f
    return fib[n]
def fib_optimized(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    if n == 0:
        return 0
    prev = 0
    res = 1
    next = 0
    for i in range(2, n + 1):
        next = prev + res
        prev = res
        res = next
    return res
def fib_binet(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    square_root_of_5 = math.sqrt(5)
    phi = (1 + square_root_of_5) / 2
    return int((math.pow(phi, n) - math.pow(-phi, -n)) / square_root_of_5)
def main():
    n = int(input("Enter a non-negative integer: "))
    print("Main number using Memoization:", fib_memo(n))
    print("Main number using Bottom-Up:", fib_bot_up(n))
    print("Main number using Optimized Approach:", fib_optimized(n))
    print("Main number using Binet's Formula:", fib_binet(n))
if __name__ == "__main__":
    main()
