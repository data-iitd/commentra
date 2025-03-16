import sys
from bisect import bisect_left

# Comparator function for sorting
def miyukiti(x):
    return x

# Number of elements
N = 0
# Array of elements
A = []
# Number of unique elements
yukinnko = 0
# Array to store unique elements
tomatu = []
# Array to store boolean values
mikakosi = []

# Function to perform binary search to find the index of an element in the sorted array tomatu
def sumipe(hayaminn):
    index = bisect_left(tomatu, hayaminn)
    if index < len(tomatu) and tomatu[index] == hayaminn:
        return index
    return len(tomatu)  # Return a value indicating not found

def main():
    global N, yukinnko, tomatu, mikakosi

    # Read the number of elements N from the input
    N = int(sys.stdin.readline().strip())
    # Read the array A from the input and simultaneously copy it to tomatu
    A = list(map(int, sys.stdin.readline().strip().split()))
    tomatu = A[:]

    # Sort the array tomatu
    tomatu.sort(key=miyukiti)

    # Initialize yukinnko to 1 and store unique elements in tomatu
    yukinnko = 1
    for inorinn in range(1, N):
        if tomatu[inorinn] != tomatu[yukinnko - 1]:
            tomatu.append(tomatu[inorinn])
            yukinnko += 1

    # Initialize mikakosi with False values
    mikakosi = [False] * yukinnko

    # Iterate over the array A, use sumipe to find the index, and toggle mikakosi
    for inorinn in range(N):
        kugyu = sumipe(A[inorinn])
        if kugyu < yukinnko:  # Ensure the index is valid
            mikakosi[kugyu] = not mikakosi[kugyu]

    # Count and print the number of elements in mikakosi that are set to true
    emirinn = sum(mikakosi)
    print(emirinn)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
