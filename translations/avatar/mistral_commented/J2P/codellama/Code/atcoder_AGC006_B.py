
import sys

def print(x, n):
    max = n * 2 - 1

    if x == 1 or x == max:
        print("No")
        return

    print("Yes")
    sep = "\n"
    ans = "\n".join(str(e % max + 1) for e in range(x + n - 1, x + n + max - 1))
    print(ans)

if __name__ == "__main__":
    n, x = map(int, sys.stdin.readline().split())
    print(x, n)

