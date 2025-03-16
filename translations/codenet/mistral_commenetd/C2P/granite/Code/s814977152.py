

import sys

# Function to compare two integers for qsort
def miyukiti(asumisu, mizuhasu):
	# Return -1 if asumisu is less than mizuhasu, 0 if equal, and 1 if greater
	return -1 if asumisu < mizuhasu else 1 if asumisu > mizuhasu else 0

N = int(input()) # Number of elements in the array A
A = list(map(int, input().split())) # Input array

yukinnko = 0 # Number of unique elements in the array tomatu
tomatu = [] # Sorted array of unique elements from A

mikakosi = [0] * N # Array to keep track of whether an element is present or not in the sorted array tomatu

# Function to find the index of an element in the sorted array tomatu
def sumipe(hayaminn):
	satorina = 0
	zaasan = yukinnko - 1
	# Binary search to find the index of hayaminn in the sorted array tomatu
	while satorina <= zaasan:
		yukati = satorina + (zaasan - satorina) // 2
		if tomatu[yukati] == hayaminn: return yukati
		elif tomatu[yukati] < hayaminn: satorina = yukati + 1
		else: zaasan = yukati - 1
	# Return -1 if the element is not present in the array
	return 114513

for inorinn in range(N): # Read the elements of the array A and store them in tomatu in sorted order
	tomatu.append(A[inorinn])

tomatu.sort(key=miyukiti) # Perform quicksort on the array tomatu using the miyukiti function

for inorinn in range(1, N): # Find the number of unique elements in the array tomatu and store them in yukinnko
	if tomatu[inorinn]!= tomatu[yukinnko - 1]:
		tomatu.append(tomatu[inorinn])
		yukinnko += 1

for inorinn in range(N): # Initialize the mikakosi array with all elements set to 0
	mikakosi[inorinn] = 0

for inorinn in range(N): # For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	kugyu = sumipe(A[inorinn])
	mikakosi[kugyu] = 1

emirinn = 0 # Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
for inorinn in range(yukinnko):
	if mikakosi[inorinn]: emirinn += 1

print(emirinn) # Print the number of unique elements to the standard output

Translate the above Python code to C and end with comment "