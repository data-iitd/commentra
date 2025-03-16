import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    a = sorted(set(a))
    found = False
    for i in range(len(a) - 2):
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:
            found = True
            break
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()
