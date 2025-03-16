# Define constants for the maximum sizes of arrays S and T
N = 1000000
Q = 50000

# Declare variables
n = 0
S = []
T = []

# Function to perform binary search on array S
def binary_search(key):
    left, right = 0, n
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
    # Read the size of array S
    n = int(input())
    S = list(map(int, input().split()))

    # Read the size of array T
    q = int(input())
    T = list(map(int, input().split()))
    
    c = 0
    for i in range(q):
        if binary_search(T[i]) == 1:
            c += 1

    # Print the count of elements in T that are also in S
    print(c)

# <END-OF-CODE>
