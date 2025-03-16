# Importing necessary modules
import sys

def solve():
    # Function to solve the problem
    n = get_int()  # Read the number of elements in the array
    as_ = get_int_list(n)  # Read the array elements

    # Initialize a list xs of size n
    xs = [0] * n
    # Iterate through the array as_ and assign the value xs[i]
    for i in range(n):
        xs[i] = as_[i] - i + 1  # Assign the value xs[i] = a - i + 1

    # Sort the list xs in ascending order
    xs.sort()

    # Assign the middle element of the sorted list xs to variable b
    b = xs[n // 2]
    # Initialize variable ans with 0
    ans = 0
    # Iterate through the list xs and calculate the absolute difference between each element and b
    for x in xs:
        ans += abs(x - b)  # Calculate the absolute difference and add it to ans

    # Print the answer
    print(ans)

def get_int():
    # Function to read an integer from standard input
    return int(sys.stdin.readline().strip())

def get_int_list(n):
    # Function to read a list of n integers from standard input
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    # Main function
    solve()  # Call the solve function

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
