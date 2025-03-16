# Declare variables
N = int(input())
A = list(map(int, input().split()))

# Initialize swap count
count = 0

# Perform bubble sort on the array A
for i in range(N - 1):
    for j in range(N - 1, i, -1):
        # Compare adjacent elements and swap if they are in the wrong order
        if A[j] < A[j - 1]:
            A[j], A[j - 1] = A[j - 1], A[j]  # Swap elements

            # Increment the swap count
            count += 1

# Output the sorted array
print(" ".join(map(str, A)))

# Print the total number of swaps made during sorting
print(count)

# <END-OF-CODE>
