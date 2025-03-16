
import math

def sub(a, b):
    min = min(a, b)
    max = max(a, b)
    result = 0
    while min > 0:
        result += max // min
        max = max % min
        min, max = min(min, max), max(min, max)
    return result


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        a, b = map(int, input().split())
        print(sub(a, b))

