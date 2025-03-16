import sys
from bisect import bisect_left

def miyukiti(asumisu, mizuhasu):
    # Compare two integers for sorting
    return (asumisu > mizuhasu) - (asumisu < mizuhasu)

N = int(sys.stdin.readline().strip())  # Number of elements in the array A
A = list(map(int, sys.stdin.readline().strip().split()))  # Input array

# Sort and get unique elements
tomatu = sorted(set(A))
yukinnko = len(tomatu)  # Number of unique elements

# Initialize the mikakosi array
mikakosi = [0] * yukinnko

# For each element in the array A, find its index in the sorted array tomatu
for element in A:
    kugyu = bisect_left(tomatu, element)
    if kugyu < yukinnko and tomatu[kugyu] == element:
        mikakosi[kugyu] = 1

# Count the number of unique elements marked in mikakosi
emirinn = sum(mikakosi)

# Print the number of unique elements
print(emirinn)

# End of code
# <END-OF-CODE>
