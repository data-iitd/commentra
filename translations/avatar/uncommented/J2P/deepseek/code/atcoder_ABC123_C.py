import math
import sys

def main():
    N = int(input())
    min_val = int(input())
    for _ in range(4):
        min_val = min(min_val, int(input()))
    print(math.ceil(N / min_val) + 4)

if __name__ == "__main__":
    main()
