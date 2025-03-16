def sub(a, b):
    min_val = min(a, b)
    max_val = max(a, b)
    result = 0

    while min_val > 0:
        result += max_val // min_val
        max_val %= min_val
        min_val, max_val = min(min_val, max_val), max(min_val, max_val)

    return result


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    index = 1

    for _ in range(n):
        a = int(data[index])
        b = int(data[index + 1])
        index += 2
        print(sub(a, b))


main()
