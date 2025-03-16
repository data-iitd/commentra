def fib_memo(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    if n in cache:
        return cache[n]
    if n <= 1:
        f = n
    else:
        f = fib_memo(n - 1) + fib_memo(n - 2)
        cache[n] = f
    return f


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


def fib_optimized(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    if n == 0:
        return 0
    prev, res = 0, 1
    for i in range(2, n + 1):
        next_fib = prev + res
        prev, res = res, next_fib
    return res


def fib_binet(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    square_root_of_5 = 5 ** 0.5
    phi = (1 + square_root_of_5) / 2
    return int((phi ** n - (-phi) ** -n) / square_root_of_5)


cache = {}


def main():
    n = int(input())
    print("Main number using Memoization:", fib_memo(n))
    print("Main number using Bottom-Up:", fib_bot_up(n))
    print("Main number using Optimized Approach:", fib_optimized(n))
    print("Main number using Binet's Formula:", fib_binet(n))


main()
