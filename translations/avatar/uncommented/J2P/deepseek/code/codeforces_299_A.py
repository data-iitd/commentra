import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    a.sort()
    min_val = a[0]
    for value in a:
        if value % min_val != 0:
            print(-1)
            return
    print(min_val)

if __name__ == "__main__":
    main()
