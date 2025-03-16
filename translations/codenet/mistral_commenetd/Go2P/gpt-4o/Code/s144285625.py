import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Reading the number of elements in the array
    n = next_int()

    # Reading elements of the array
    ar = list(map(int, sys.stdin.readline().strip().split()))

    # Sorting the array in ascending order
    ar.sort()

    # Calculating the sum of elements at index 3n-2i-1 in the sorted array
    total_sum = 0
    for i in range(n):
        total_sum += ar[3*n - (i + 1) * 2]

    # Printing the result
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
