import sys

# Define a large prime number for modulo operations
mod = int(1e9 + 7)

# Variables to store the number of elements, a threshold value, and the array of long integers
n = 0
k = 0
a = []

def check(x):
    global n, a
    tot = 0  # Total count of valid pairs

    # Iterate through each element in the array
    for i in range(n):
        now = a[i]  # Current element
        l, r = 0, n  # Initialize binary search bounds

        # If the current element is non-negative
        if now >= 0:
            # Perform binary search to count valid pairs
            while l < r:
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1  # Move right if the product is less than x
                else:
                    r = c  # Move left otherwise
            tot += l  # Add the count of valid pairs
        else:
            # If the current element is negative
            while l < r:
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1  # Move right if the product is greater than or equal to x
                else:
                    r = c  # Move left otherwise
            tot += (n - l)  # Count valid pairs with negative current element

        # Adjust total count if the product of the element with itself is less than x
        if now * now < x:
            tot -= 1

    # Return true if the total count of pairs is less than k
    return tot // 2 < k

def main():
    global n, k, a

    # Read the number of elements and the threshold value k
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())

    # Read the elements into the array
    a = list(map(int, sys.stdin.readline().strip().split()))

    # Sort the array to facilitate binary search
    a.sort()

    # Define a large value for infinity
    INF = int(1e18) + 1

    # Set the initial bounds for binary search
    l, r = -INF, INF

    # Perform binary search to find the maximum value satisfying the condition
    while l + 1 < r:
        c = (l + r) // 2
        if check(c):
            l = c  # If check returns true, move the lower bound up
        else:
            r = c  # Otherwise, move the upper bound down

    # Output the result
    print(l)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
