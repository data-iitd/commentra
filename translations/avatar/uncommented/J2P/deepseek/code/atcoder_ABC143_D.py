import sys

def find(li, from_idx, target):
    low = from_idx
    upp = len(li) - 1
    mid = (low + upp) // 2 + (1 if (upp - low + 1) % 2 != 0 else 0)
    if upp - low < 0:
        return 0
    elif li[from_idx] >= target:
        return 0
    elif li[upp] < target:
        return upp - from_idx + 1
    while upp - low > 1:
        if li[mid] >= target:
            upp = mid
        else:
            low = mid
        mid = (low + upp) // 2 + (1 if (upp - low + 1) % 2 != 0 else 0)
    return low - from_idx + 1

def main():
    scanner = sys.stdin
    N = int(next(scanner))
    L = list(map(int, next(scanner).split()))
    L.sort()
    count = 0
    for i in range(N):
        for j in range(i + 1, N):
            a = L[i]
            b = L[j]
            res = find(L, j + 1, a + b)
            count += res
    print(count)

if __name__ == "__main__":
    main()
