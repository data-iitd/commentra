
import sys

# Comparison function for sorted() to sort integers
def miyukiti(asumisu, mizuhasu):
    return asumisu < mizuhasu

# Read the number of elements
N = int(input())

# Read the elements into array A and copy to tomatu
A = [int(input()) for _ in range(N)]
tomatu = A[:]

# Sort the array of elements
tomatu.sort(key=miyukiti)

# Remove duplicates from the sorted array
yukinnko = 1
for inorinn in range(1, N):
    if tomatu[inorinn]!= tomatu[yukinnko - 1]:
        tomatu[yukinnko] = tomatu[inorinn]
        yukinnko += 1

# Track occurrences of each element in the original array
mikakosi = [0] * yukinnko
for inorinn in range(N):
    kugyu = tomatu.index(A[inorinn])
    mikakosi[kugyu] = 1 - mikakosi[kugyu]

# Count the number of unique elements
emirinn = sum(mikakosi)

# Output the count of unique elements
print(emirinn)

