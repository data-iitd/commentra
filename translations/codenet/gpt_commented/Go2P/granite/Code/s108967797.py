
import sys

# Function to read an integer from input
def ri():
    return int(input())

# Function to calculate the average of a list of numbers
def ave(l):
    return sum(l) / len(l)

# Function to calculate the absolute difference between two numbers
def diff(a, b):
    return abs(a - b)

def main():
    n = ri() # Read the number of elements
    a = [ri() for _ in range(n)] # Read the float64 numbers and store them in a list
    # print(a) # Uncomment to print the list of float64 numbers

    # Calculate the average of the numbers
    ave = ave(a)

    # Initialize variables to track the minimum difference and the corresponding index
    minDiff = 999999.9
    ansIndex = -1
    for i, v in enumerate(a): # Iterate over the list to find the closest value to the average
        diff = diff(v, ave) # Calculate the difference between the current value and the average
        if diff < minDiff: # Check if the current difference is less than the minimum difference found so far
            minDiff = diff # Update the minimum difference
            ansIndex = i # Update the index of the closest value
    # Print the index of the value closest to the average
    print(ansIndex)

if __name__ == "__main__":
    main()

