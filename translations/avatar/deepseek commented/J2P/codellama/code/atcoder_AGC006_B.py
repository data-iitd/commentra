import sys

def print(x, n):
    max = n * 2 - 1
    if x == 1 or x == max:
        print("No")
        return
    print("Yes")
    sep = sys.stdout.write("\n")
    ans = "".join(str((i % max + 1)) + sep for i in range(x + n - 1, x + n + max - 1))
    print(ans)

if __name__ == "__main__":
    n, x = map(int, input().split())
    print(x, n)

