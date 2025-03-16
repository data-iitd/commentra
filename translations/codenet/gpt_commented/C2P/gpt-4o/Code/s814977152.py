import sys
from bisect import bisect_left

# Comparison function for sorting integers
def miyukiti(x):
    return x

# Global variables
N = 0  # Number of elements
A = []  # List to hold input elements

yukinnko = 0  # Count of unique elements
tomatu = []  # List to hold sorted elements

mikakosi = []  # List to track occurrences of elements

# Function to perform binary search on the sorted list
def sumipe(hayaminn):
    satorina = 0
    zaasan = yukinnko - 1
    while satorina <= zaasan:
        yukati = satorina + (zaasan - satorina) // 2
        if tomatu[yukati] == hayaminn:
            return yukati  # Found the element
        elif tomatu[yukati] < hayaminn:
            satorina = yukati + 1  # Search in the right half
        else:
            zaasan = yukati - 1  # Search in the left half
    return 114513  # Element not found

# Main function
def main():
    global N, yukinnko, tomatu, mikakosi

    # Read the number of elements
    N = int(sys.stdin.readline().strip())

    # Read the elements into list A and copy to tomatu
    A = list(map(int, sys.stdin.readline().strip().split()))
    tomatu = A.copy()  # Copying input to sorted list

    # Sort the list of elements
    tomatu.sort(key=miyukiti)

    # Remove duplicates from the sorted list
    yukinnko = 1  # Start with the first unique element
    for inorinn in range(1, N):
        if tomatu[inorinn] != tomatu[yukinnko - 1]:
            tomatu[yukinnko] = tomatu[inorinn]  # Add unique element
            yukinnko += 1

    # Initialize occurrences tracking list
    mikakosi = [0] * yukinnko

    # Track occurrences of each element in the original list
    for inorinn in range(N):
        kugyu = sumipe(A[inorinn])  # Find index of element in sorted list
        if kugyu < yukinnko:
            mikakosi[kugyu] ^= 1  # Toggle occurrence

    # Count the number of unique elements
    emirinn = sum(1 for count in mikakosi if count)

    # Output the count of unique elements
    print(emirinn)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
