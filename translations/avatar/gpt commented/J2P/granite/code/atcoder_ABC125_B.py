
import sys

def main():
    # Read the number of items (n) from the input
    n = int(input())

    # Read the values (vStr) from the input and convert to a list
    vStr = input()
    vList = str2List(vStr)

    # Read the costs (cStr) from the input and convert to a list
    cStr = input()
    cList = str2List(cStr)

    # Initialize a variable to keep track of the maximum profit
    max = 0

    # Calculate the profit for each item and sum up the positive profits
    for i in range(n):
        profit = vList[i] - cList[i]
        # Only add to max if the profit is positive
        if profit > 0:
            max += profit

    # Output the total maximum profit
    print(max)

# Helper method to convert a space-separated string of integers into a list
def str2List(str):
    # Split the input string into an array of strings
    vArrStr = str.split(" ")

    # Create a list to hold the integer values
    ret = []

    # Populate the list with values from the array
    for val in vArrStr:
        ret.append(int(val))

    # Return the populated list
    return ret

if __name__ == "__main__":
    main()

