import sys
import bisect

# Function to read a single integer from stdin
def int_scanner():
    return int(sys.stdin.readline().strip())

# Initialize the modulus value
mod = 1000000007

# Function to read input and process it
def main():
    # Read the number of elements in the array
    n = int_scanner()

    # Read the elements of the array into the as list
    as_list = [int_scanner() for _ in range(n)]

    # Initialize an empty list xs to store the unique elements
    xs = [as_list[0]]

    # Iterate through the array and add unique elements to the xs list
    for j in range(1, n):
        # Binary search to find the index where the current element should be inserted in the xs list
        idx = bisect.bisect_left(xs, as_list[j])

        # If the current element is not already present in the xs list, append it
        if idx == len(xs):
            xs.append(as_list[j])
        else:
            # Otherwise, replace the element at the found index with the current element
            xs[idx] = as_list[j]

    # Print the length of the xs list
    print(len(xs))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
