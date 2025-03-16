
import sys

def binary_search(A, key):
    left = 0
    right = len(A) - 1
    while left < right:
        mid = (left + right) // 2
        if key == A[mid]:
            return True
        elif key > A[mid]:
            left = mid + 1
        else:
            right = mid
    return False

def main():
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())
    sum = 0
    for _ in range(q):
        k = int(input())
        if binary_search(A, k):
            sum += 1
    print(sum)

if __name__ == "__main__":
    main()

