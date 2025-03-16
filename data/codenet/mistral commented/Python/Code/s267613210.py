# Import necessary modules
import sys

# Function to read input as a list of integers from standard input
def input():
    return sys.stdin.readline().rstrip()

# Function to read a list of integers from a single line of input
def input_nums():
    return list(map(int, input().split()))

# Main function to solve the problem
def main():
    # Read the number of tests and the number of elements in the array from input
    K, N = input_nums()

    # Read the array A from input
    A = input_nums()

    # Calculate the differences between adjacent elements in the array A
    dist = []
    for i in range(len(A)-1):
        dist.append(A[i+1]-A[i])

    # Append the difference between the last element of the array and the constant K to the list dist
    dist.append(K+A[0]-A[-1])

    # Find the maximum difference in the list dist
    maxv = max(dist)

    # Print the sum of all differences in the list dist minus the maximum difference
    print(sum(dist) - maxv)

# Run the main function if the script is run as the main program
if __name__ == '__main__':
    main()
