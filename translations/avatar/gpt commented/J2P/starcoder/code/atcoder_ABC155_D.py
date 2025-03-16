import sys

# Define a large prime number for modulo operations
mod = 1000000007

# Direction vectors for potential grid movements (not used in this code)
DX = [-1, 0, 1, 0]
DY = [0, -1, 0, 1]

# Variables to store the number of elements, a threshold value, and the array of long integers
n = 0
k = 0
a = []

# Function to check if a certain value x can be achieved
def check(x):
    tot = 0 # Total count of valid pairs

    # Iterate through each element in the array
    for i in range(n):
        now = a[i] # Current element
        l = 0
        r = n

        # If the current element is non-negative
        if now >= 0:
            # Perform binary search to count valid pairs
            while l < r:
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1 # Move right if the product is less than x
                else:
                    r = c # Move left otherwise
            tot += l # Add the count of valid pairs
        else:
            # If the current element is negative
            while l < r:
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1 # Move right if the product is greater than or equal to x
                else:
                    r = c # Move left otherwise
            tot += (n - l) # Count valid pairs with negative current element

        # Adjust total count if the product of the element with itself is less than x
        if a[i] * a[i] < x:
            tot -= 1

    # Return true if the total count of pairs is less than k
    if tot // 2 < k:
        return True
    else:
        return False

# Main function
if __name__ == "__main__":
    # Initialize scanner for input
    fs = sys.stdin

    # Read the number of elements and the threshold value k
    n = int(fs.readline())
    k = int(fs.readline())

    # Initialize the array to hold the long integers
    a = [0] * n

    # Read the elements into the array
    for i in range(n):
        a[i] = int(fs.readline())

    # Sort the array to facilitate binary search
    a.sort()

    # Define a large value for infinity
    INF = 1000000000000000000 + 1

    # Set the initial bounds for binary search
    l = -INF
    r = INF

    # Perform binary search to find the maximum value satisfying the condition
    while l + 1 < r:
        c = (l + r) // 2
        if check(c):
            l = c # If check returns true, move the lower bound up
        else:
            r = c # Otherwise, move the upper bound down

    # Output the result
    print(l)

# 