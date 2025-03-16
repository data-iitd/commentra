import sys

# Define a large constant for infinity
inf = int(1e14)

def min(*args):
    return min(args)

def max(*args):
    return max(args)

def main():
    # Read the number of elements and the value of x
    n, x = map(int, sys.stdin.readline().split())

    # Create a list to hold the input integers
    a = list(map(int, sys.stdin.readline().split()))

    # Create a copy of the list a for manipulation
    v = a.copy()

    # Initialize the answer to infinity
    ans = inf

    # Iterate over each possible k value
    for k in range(n):
        kans = 0  # Initialize the current answer for this k

        # Calculate the minimum values for the current k
        for i in range(n):
            if i - k < 0:
                # If i-k is out of bounds, use the wrapped index
                v[i] = min(v[i], a[n + i - k])
            else:
                # Otherwise, use the normal index
                v[i] = min(v[i], a[i - k])
            # Accumulate the current answer
            kans += v[i]

        # Update the overall answer with the minimum found so far
        ans = min(ans, kans + k * x)

    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
