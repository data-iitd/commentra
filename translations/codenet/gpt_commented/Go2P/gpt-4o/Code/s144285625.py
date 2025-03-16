import sys

def main():
    # Read the number of groups of three integers
    n = int(sys.stdin.readline().strip())

    # Initialize a list to hold 3*n integers
    ar = list(map(int, sys.stdin.readline().strip().split()))

    # Sort the list of integers in ascending order
    ar.sort()

    # Initialize a variable to hold the sum of selected integers
    sum_selected = 0

    # Calculate the sum of the second largest integer from each group of three
    for i in range(n):
        sum_selected += ar[3*n - (i + 1) * 2]  # Select the second largest integer from the sorted list

    # Print the final computed sum
    print(sum_selected)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
