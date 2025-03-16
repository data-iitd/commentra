import math

def sub(a, b):
    min = min(a, b)
    max = max(a, b)
    result = 0

    while min > 0:
        result += max // min
        max = max % min
        curr_min = min(min, max)
        curr_max = max(min, max)
        min = curr_min
        max = curr_max

    return result


def main():
    n = int(input())

    for i in range(n):
        a = int(input())
        b = int(input())
        print(sub(a, b))


if __name__ == "__main__":
    main()

