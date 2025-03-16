def binary_search(A, n, key):
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if key == A[mid]:
            return 1  # key found
        if key > A[mid]:
            left = mid + 1  # search in the right half
        else:
            right = mid  # search in the left half
    return 0

def main():
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())
    sum_count = 0
    for _ in range(q):
        k = int(input())
        if binary_search(A, n, k):
            sum_count += 1
    print(sum_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
