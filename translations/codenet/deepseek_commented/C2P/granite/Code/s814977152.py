
import sys

# Comparator function for sorted tomatu
def miyukiti(asumisu, mizuhasu):
    return asumisu < mizuhasu

# Read the number of elements N from the input
N = int(input())
# Read the array A from the input and simultaneously copy it to tomatu
A = list(map(int, input().split()))
tomatu = A[:]
# Sort the array tomatu using the comparator function miyukiti
tomatu.sort(key=miyukiti)
# Initialize yukinnko to 1 and store unique elements in tomatu
yukinnko = 1
for inorinn in range(1, N):
    if tomatu[inorinn]!= tomatu[yukinnko - 1]:
        tomatu[yukinnko] = tomatu[inorinn]
        yukinnko += 1
# Initialize mikakosi to all False
mikakosi = [False] * yukinnko
# Iterate over the array A, use sumipe to find the index, and toggle mikakosi
for inorinn in range(N):
    kugyu = tomatu.index(A[inorinn])
    mikakosi[kugyu] = not mikakosi[kugyu]
# Count and print the number of elements in mikakosi that are True
emirinn = sum(mikakosi)
print(emirinn)

