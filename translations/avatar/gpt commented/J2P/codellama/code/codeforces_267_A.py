import math

def sub(a, b):
    min = math.min(a, b)
    max = math.max(a, b)
    result = 0
    while min > 0:
        result += max // min
        max = max % min
        min = math.min(min, max)
        max = math.max(min, max)
    return result

def main():
    n = int(input())
    for i in range(n):
        a, b = map(int, input().split())
        print(sub(a, b))

if __name__ == "__main__":
    main()

