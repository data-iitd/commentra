def binary_search(key, A):
    left = 0
    right = len(A)
    while left < right:
        mid = (left + right) // 2
        if key == A[mid]:
            return 1  # keyを発見
        elif key > A[mid]:
            left = mid + 1  # 後半を探索
        else:
            right = mid  # 前半を探索
    return 0

n = int(input())
A = list(map(int, input().split()))
q = int(input())
sum_ = 0
for _ in range(q):
    k = int(input())
    if binary_search(k, A):
        sum_ += 1
print(sum_)
