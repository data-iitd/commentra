import sys

# Function to read an integer from standard input
def ri():
    n = 0
    for v in input().strip():
        n = n * 10 + int(v)
    return n

# Function to calculate the average of a list of float numbers
def ave(s):
    return sum(s) / len(s)

# Function to calculate the difference between two float numbers
def diff(a, b):
    return abs(a - b)

# Main function
def main():
    # Read the number of elements in the array from standard input
    n = ri()

    # Read each element of the array from standard input and store it in the corresponding index
    a = [ri() for _ in range(n)]

    # Calculate the average of the array elements
    ave_val = ave(a)

    # Initialize variables to store the minimum difference and the index of the element with the minimum difference
    min_diff = float('inf')
    ans_index = -1

    # Iterate through each element of the array and find the one with the minimum difference from the average
    for i, v in enumerate(a):
        current_diff = diff(v, ave_val)
        if current_diff < min_diff:
            min_diff = current_diff
            ans_index = i

    # Print the index of the element with the minimum difference from the average
    print(ans_index)

# Call the main function
main()

