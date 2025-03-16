
import sys

def sub(a, b):
    min_num = min(a, b)
    max_num = max(a, b)
    result = 0

    while min_num > 0:
        result += max_num // min_num
        max_num = max_num % min_num
        min_num, max_num = min(min_num, max_num), max(min_num, max_num)

    return result

def main():
    n = int(input())

    for i in range(n):
        a, b = map(int, input().split())
        print(sub(a, b))

if __name__ == "__main__":
    main()

