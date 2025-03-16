import sys

# Function to read an integer from standard input
def ri():
    return int(sys.stdin.readline().strip())

# Function to calculate the average of a list of float numbers
def ave(s):
    return sum(s) / len(s)  # Calculate and return the average

# Function to calculate the difference between two float numbers
def diff(a, b):
    return abs(a - b)  # Return the absolute difference

# Main function
def main():
    n = ri()  # Read the number of elements in the array from standard input

    a = []  # Initialize an empty list to store float numbers

    # Read each element of the array from standard input and store it in the list
    for _ in range(n):
        a.append(float(ri()))  # Read an integer from standard input and convert it to a float

    # Calculate the average of the array elements
    average = ave(a)

    # Initialize variables to store the minimum difference and the index of the element with the minimum difference
    min_diff = float('inf')
    ans_index = -1

    # Iterate through each element of the array and find the one with the minimum difference from the average
    for i, v in enumerate(a):
        d = diff(v, average)  # Calculate the difference between the current element and the average
        if d < min_diff:  # Check if the difference is smaller than the current minimum difference
            min_diff = d  # If so, update the minimum difference
            ans_index = i  # and the index of the answer

    # Print the index of the element with the minimum difference from the average
    print(ans_index)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
