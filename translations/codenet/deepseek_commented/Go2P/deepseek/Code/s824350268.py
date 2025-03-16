import math

def main():
    N = int(input())
    sqrtN = int(math.sqrt(N))

    min_sum = N
    for i in range(1, sqrtN + 1):
        if N % i == 0:
            num = i + (N // i) - 2
            if num < min_sum:
                min_sum = num

    print(min_sum)

