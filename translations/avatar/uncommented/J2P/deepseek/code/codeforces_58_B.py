import sys

def main():
    n = int(input().strip())
    m = n
    for i in range(n - 1, 0, -1):
        if m % i == 0:
            print(i, end=' ')
            m = i

if __name__ == "__main__":
    main()
