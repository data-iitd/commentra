import sys

def main():
    n, m = map(int, sys.stdin.readline().split())

    # Calculate the number of ways to choose 2 items from n items
    ans = n * (n - 1) // 2

    # Calculate the number of ways to choose 2 items from m items
    ans += m * (m - 1) // 2

    print(ans)

if __name__ == "__main__":
    main()
