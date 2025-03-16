import sys

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
    input_data = sys.stdin.readline()
    n = int(input_data)
    for _ in range(n):
        input_data = sys.stdin.readline()
        a, b = map(int, input_data.split())
        print(sub(a, b))

if __name__ == "__main__":
    main()
