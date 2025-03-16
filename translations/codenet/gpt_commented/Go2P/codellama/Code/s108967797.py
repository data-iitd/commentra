
import sys

# Function to read an integer from input
def ri():
    return int(sys.stdin.readline().strip())

# Function to calculate the average of a list of float numbers
def ave(s):
    return sum(s) / len(s)

# Function to calculate the absolute difference between two float numbers
def diff(a, b):
    if a > b:
        return a - b
    return b - a

# Main function
def main():
    n = ri()
    a = [float(ri()) for _ in range(n)]
    # print(a)

    # Calculate the average of the numbers
    ave = ave(a)

    # Initialize variables to track the minimum difference and the corresponding index
    minDiff = 999999.9
    ansIndex = -1
    for i, v in enumerate(a):
        diff = diff(v, ave)
        if diff < minDiff:
            minDiff = diff
            ansIndex = i

    # Print the index of the value closest to the average
    print(ansIndex)


if __name__ == "__main__":
    main()


