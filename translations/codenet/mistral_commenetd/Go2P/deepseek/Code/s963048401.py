import sys
import bisect

# Function to read a single string from stdin
def input():
    return sys.stdin.readline().strip()

# Function to read an integer from stdin
def int_input():
    return int(input())

# Function to read a floating point number from stdin
def float_input():
    return float(input())

# Function to read input and process it
def main():
    # Read the number of elements in the array
    n = int_input()

    # Read the elements of the array into the as list
    as = [int_input() for _ in range(n)]

    # Initialize an empty list xs to store the unique elements
    xs = [as[0]]

    # Iterate through the array and add unique elements to the xs list
    for j in range(1, n):
        # Binary search to find the index where the current element should be inserted in the xs list
        idx = bisect.bisect_left(xs, as[j])

        # If the current element is not already present in the xs list, append it
        if idx == len(xs):
            xs.append(as[j])
        else:
            # Otherwise, replace the element at the found index with the current element
            xs[idx] = as[j]

    # Print the length of the xs list
    print(len(xs))

# Call the main function
if __name__ == "__main__":
    main()
