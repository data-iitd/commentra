def binary_search(key, A, n):
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if key == A[mid]:
            return 1
        if key > A[mid]:
            left = mid + 1
        else:
            right = mid
    return 0

n = int(input())
A = list(map(int, input().split()))
q = int(input())
sum_ = 0

for _ in range(q):
    k = int(input())
    if binary_search(k, A, n):
        sum_ += 1

print(sum_)
