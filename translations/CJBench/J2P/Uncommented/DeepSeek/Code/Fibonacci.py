import sys
from typing import Dict

def fib_memo(n: int, cache: Dict[int, int]) -> int:
    if n < 0:
        raise ValueError("Input n must be non-negative")
    if n in cache:
        return cache[n]
    f: int
    if n <= 1:
        f = n
    else:
        f = fib_memo(n - 1, cache) + fib_memo(n - 2, cache)
        cache[n] = f
    return f

def fib_bot_up(n: int) -> int:
    if n < 0:
        raise ValueError("Input n must be non-negative")
    fib: Dict[int, int] = {}
    for i in range(n + 1):
        f: int
        if i <= 1:
            f = i
        else:
            f = fib[i - 1] + fib[i - 2]
        fib[i] = f
    return fib[n]

def fib_optimized(n: int) -> int:
    if n < 0:
        raise ValueError("Input n must be non-negative")
    if n == 0:
        return 0
    prev, res = 0, 1
    for i in range(2, n + 1):
        prev, res = res, prev + res
    return res

def fib_binet(n: int) -> int:
    if n < 0:
        raise ValueError("Input n must be non-negative")
    square_root_of_5 = 5 ** 0.5
    phi = (1 + square_root_of_5) / 2
    return int((phi ** n - (-phi) ** -n) / square_root_of_5)

def main():
    n = int(sys.stdin.readline().strip())
    print("Main number using Memoization:", fib_memo(n, {}))
    print("Main number using Bottom-Up:", fib_bot_up(n))
    print("Main number using Optimized Approach:", fib_optimized(n))
    print("Main number using Binet's Formula:", fib_binet(n))

if __name__ == "__main__":
    main()
