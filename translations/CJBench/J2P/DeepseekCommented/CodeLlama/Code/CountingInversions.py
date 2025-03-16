
import sys

def count_inversions(arr):
    if len(arr) == 1:
        return 0
    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    left_inv = count_inversions(left)
    right_inv = count_inversions(right)
    inv = merge_and_count(left, right)
    return left_inv + right_inv + inv

def merge_and_count(left, right):
    i, j = 0, 0
    inv = 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            inv += len(left) - i
            j += 1
    result += left[i:]
    result += right[j:]
    return inv

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    result = count_inversions(arr)
    print("Number of inversions:", result)

