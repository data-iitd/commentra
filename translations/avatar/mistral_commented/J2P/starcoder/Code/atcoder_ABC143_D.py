
import sys

def find(li, from_, target):
    low = from_
    upp = len(li) - 1
    mid = 0

    if upp - low < 0:
        return 0
    elif li[from_] >= target:
        return 0
    elif li[upp] < target:
        return upp - low + 1

    while upp - low > 1:
        mid = (upp - low + 1) % 2 == 0 and (low + upp) / 2 + 1 or (low + upp) / 2

        if li[mid] >= target:
            upp = mid
        else:
            low = mid

    return low - from_ + 1

def main():
    N = int(raw_input())
    L = []
    for i in range(N):
        L.append(int(raw_input()))
    L.sort()
    count = 0
    for i in range(N):
        for j in range(i + 1, N):
            a = L[i]
            b = L[j]
            res = find(L, j + 1, a + b)
            count = count + res
    print count

if __name__ == "__main__":
    main()

