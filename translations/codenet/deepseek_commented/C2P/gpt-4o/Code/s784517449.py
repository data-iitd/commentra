# Define a global list A and a variable n
A = []
n = 0

def binary_search(key):
    """
    binary_search function performs a binary search on the list A to find a given key.
    It returns True if the key is found, otherwise it returns False.
    """
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if key == A[mid]:
            return True  # key found
        if key > A[mid]:
            left = mid + 1  # search in the right half
        else:
            right = mid  # search in the left half
    return False

def main():
    global n, A
    sum_found = 0
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())
    for _ in range(q):
        k = int(input())
        if binary_search(k):
            sum_found += 1
    print(sum_found)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
