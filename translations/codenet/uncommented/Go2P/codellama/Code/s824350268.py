
import math

def main():
    N = int(input())
    sqrtN = int(math.sqrt(N))

    min = N
    for i in range(1, sqrtN + 1):
        if N % i != 0:
            continue

        num = i + (N // i) - 2
        if num < min:
            min = num

    print(min)

if __name__ == "__main__":
    main()

