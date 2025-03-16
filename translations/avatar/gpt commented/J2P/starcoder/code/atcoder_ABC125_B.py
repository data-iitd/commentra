import sys

def str2List(str):
    # Split the input string into an array of strings
    vArrStr = str.split(" ")

    # Create a Map to hold the integer values with their corresponding indices
    ret = {}
    key = 0

    # Populate the Map with values from the array
    for val in vArrStr:
        ret[key] = int(val)
        key += 1

    # Return the populated Map
    return ret

def main():
    # Read the number of items (n) from the input
    n = int(sys.stdin.readline())

    # Read the values (vStr) from the input and convert to a list
    vStr = sys.stdin.readline()
    vList = str2List(vStr)

    # Read the costs (cStr) from the input and convert to a list
    cStr = sys.stdin.readline()
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

if __name__ == "__main__":
    main()

# 