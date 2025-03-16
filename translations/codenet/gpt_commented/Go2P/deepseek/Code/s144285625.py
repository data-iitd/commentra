import sys

def input():
    return sys.stdin.readline().strip()

def next_int():
    return int(input())

def main():
    # Read the number of groups of three integers
    n = next_int()

    # Read the integers into a list
    ar = list(map(int, input().split()))

    # Sort the list of integers in ascending order
    ar.sort()

    # Initialize a variable to hold the sum of selected integers
    sum_ = 0

    # Calculate the sum of the second largest integer from each group of three
    for i in range(n):
        sum_ += ar[3*n-(i+1)*2]  # Select the second largest integer from the sorted list

    # Print the final computed sum
    print(sum_)

# Call the main function
main()

