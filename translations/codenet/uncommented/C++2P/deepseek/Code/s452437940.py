import sys

def count_multiples(a, b, x):
    count = (b // x) - (a // x)
    if a % x == 0:
        count += 1
    return count

def main():
    a, b, x = map(int, sys.stdin.readline().split())
    result = count_multiples(a, b, x)
    print(result)

if __name__ == "__main__":
    main()
