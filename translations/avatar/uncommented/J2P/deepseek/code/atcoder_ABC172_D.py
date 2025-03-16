import sys

def main():
    n = int(sys.stdin.readline().strip())
    ans = 0
    for i in range(1, n + 1):
        k = n // i
        ans += k * (k + 1) * i // 2
    print(ans)

if __name__ == "__main__":
    main()
