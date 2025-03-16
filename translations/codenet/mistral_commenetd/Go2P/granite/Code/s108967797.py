

import sys

# Function to read an integer from standard input
def ri():
    return int(input())

# Function to calculate the average of a list of numbers
def ave(l):
    return sum(l) / len(l)

# Function to calculate the difference between two numbers
def diff(a, b):
    return abs(a - b)

# Main function
if __name__ == "__main__":
    # Read the number of elements in the array from standard input
    n = ri()

    # Read each element of the array from standard input and store it in a list
    a = [ri() for _ in range(n)]

    # Print the array for debugging purposes (uncomment this line if needed)
    # print(a)

    # Calculate the average of the array elements
    ave = ave(a)

    # Initialize variables to store the minimum difference and the index of the element with the minimum difference
    minDiff = float("inf")
    ansIndex = -1

    # Iterate through each element of the array and find the one with the minimum difference from the average
    for i, v in enumerate(a):
        diff = diff(v, ave) # Calculate the difference between the current element and the average
        if diff < minDiff: # Check if the difference is smaller than the current minimum difference
            minDiff = diff # If so, update the minimum difference
            ansIndex = i    # and the index of the answer

    # Print the index of the element with the minimum difference from the average
    print(ansIndex)

# End of the code