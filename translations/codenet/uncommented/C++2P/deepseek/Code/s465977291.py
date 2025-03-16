import math

def main():
    n, d = map(int, input().split())
    a = d * 2 + 1
    result = math.ceil(n / a)
    print(result)

if __name__ == "__main__":
    main()
