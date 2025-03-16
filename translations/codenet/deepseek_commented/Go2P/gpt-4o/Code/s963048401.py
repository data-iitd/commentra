import sys
import bisect

# Function to read an integer from input
def int_scanner():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    n = int_scanner()  # Read the number of elements
    as_list = [int_scanner() for _ in range(n)]  # Read the elements into a list

    # Initialize xs with the first element of as_list
    xs = [as_list[0]]
    for j in range(1, n):
        # Use bisect to find the position to insert the current element
        idx = bisect.bisect_left(xs, as_list[j])
        if idx == len(xs):
            # If the element is larger than all elements in xs, append it
            xs.append(as_list[j])
        else:
            # Otherwise, replace the existing element at the found position
            xs[idx] = as_list[j]

    # Print the length of the longest increasing subsequence found
    print(len(xs))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
