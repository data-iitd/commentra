import sys
from bisect import bisect_left

def main():
    N = int(input())
    L = list(map(int, input().split()))
    L.sort()
    count = 0
    
    for i in range(N):
        for j in range(i + 1, N):
            a = L[i]
            b = L[j]
            target = a + b
            res = find(L, j + 1, target)
            count += res
            
    print(count)

def find(li, from_index, target):
    low = from_index
    upp = len(li) - 1
    
    if upp < low:
        return 0
    elif li[from_index] >= target:
        return 0
    elif li[upp] < target:
        return upp - low + 1
    
    while upp - low > 1:
        mid = (low + upp) // 2
        if li[mid] >= target:
            upp = mid
        else:
            low = mid
            
    return low - from_index + 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
