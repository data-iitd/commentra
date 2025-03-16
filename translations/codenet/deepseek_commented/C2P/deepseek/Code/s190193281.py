# Define constants for the maximum sizes of arrays S and T
N = 1000000
Q = 50000

# Declare variables
n = 0
S = [0] * N
T = [0] * Q

# Function to perform binary search on array S
def binary_search(key):
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if S[mid] == key:
            return 1
        elif key < S[mid]:
            right = mid
        else:
            left = mid + 1
    return 0

# Main function
if __name__ == "__main__":
    c = 0

    # Read the size of array S
    n = int(input())
    S = list(map(int, input().split()))

    # Read the size of array T
    q = int(input())
    T = list(map(int, input().split()))

    # Count the elements in T that are also in S
    for t in T:
        if binary_search(t) == 1:
            c += 1

    # Print the count of elements in T that are also in S
    print(c)

