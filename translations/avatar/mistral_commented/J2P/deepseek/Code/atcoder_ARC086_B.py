import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    r = []
    m = 0

    for i in range(1, n):
        if abs(a[m]) < abs(a[i]):
            m = i

    for i in range(n):
        if a[m] >= 0 ^ a[i] >= 0:
            r.append(f"{m+1} {i+1}")

    if a[m] >= 0:
        for i in range(1, n):
            r.append(f"{i} {i+1}")
    else:
        for i in range(n, 1, -1):
            r.append(f"{i} {i-1}")

    print(len(r))
    for pair in r:
        print(pair)

if __name__ == "__main__":
    main()

