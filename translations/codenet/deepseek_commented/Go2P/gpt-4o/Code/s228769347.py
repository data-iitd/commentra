import sys
import bisect

# Function to read integers from input and return them as a list.
def read_integers():
    return list(map(int, sys.stdin.read().split()))

# Main function to handle input/output and calculate the number of valid triplets.
def main():
    # Read the number of elements.
    data = read_integers()
    n = data[0]
    ll = data[1:n+1]

    # Sort the list ll.
    ll.sort()

    # Initialize the answer variable.
    ans = 0

    # Iterate through possible triplets (i, j, m) where i < j < m.
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            # Find the first index m such that ll[m] >= ll[i] + ll[j]
            limit = ll[i] + ll[j]
            m = bisect.bisect_left(ll, limit, j + 1, n)

            # Add the number of valid m's to the answer.
            ans += m - (j + 1)

    # Print the final answer to the standard output.
    print(ans)

# Entry point of the script.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
