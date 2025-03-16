import sys
import math

initial_buf_size = 10000
max_buf_size = 1000000
mod = 10**9 + 7

def get_int():
    return int(sys.stdin.readline().strip())

def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")
    return min(nums)

def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")
    return max(nums)

def calc_mod(x):
    return x % mod

def main():
    N = get_int()
    sqrtN = int(math.sqrt(N))

    minimum = N
    for i in range(1, sqrtN + 1):
        if N % i != 0:
            continue

        num = i + (N // i) - 2
        if num < minimum:
            minimum = num

    print(minimum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
