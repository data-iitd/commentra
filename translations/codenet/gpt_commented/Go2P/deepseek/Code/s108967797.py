import sys

# Function to read an integer from input
def ri():
    return int(sys.stdin.readline().strip())

# Function to calculate the average of a list of float numbers
def ave(s):
    return sum(s) / len(s)

# Function to calculate the absolute difference between two float numbers
def diff(a, b):
    return abs(a - b)

def main():
    n = ri()  # Read the number of elements
    a = [ri() for _ in range(n)]  # Read each integer and convert it to float

    # Calculate the average of the numbers
    ave_val = ave(a)

    # Initialize variables to track the minimum difference and the corresponding index
    min_diff = float('inf')
    ans_index = -1
    for i, v in enumerate(a):  # Iterate over the list to find the closest value to the average
        current_diff = diff(v, ave_val)  # Calculate the difference between the current value and the average
        if current_diff < min_diff:  # Check if the current difference is less than the minimum difference found so far
            min_diff = current_diff  # Update the minimum difference
            ans_index = i  # Update the index of the closest value

    # Print the index of the value closest to the average
    print(ans_index)

