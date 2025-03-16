import sys

def main():
    input = sys.stdin.readline
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    for i in range(n - 1):
        if a[i] == a[i + 1]:
            print("NO")
            return
    print("YES")

if __name__ == "__main__":
    main()
