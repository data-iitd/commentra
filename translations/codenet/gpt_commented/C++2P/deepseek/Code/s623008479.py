# Include the necessary libraries
from typing import List

# Define the main function
def main():
    # Read the values of n and k from standard input
    n, k = map(int, input().split())

    # Read the elements into a list
    l = list(map(int, input().split()))

    # Sort the list in ascending order
    l.sort()

    # Initialize a variable to hold the sum of the largest k elements
    ans = 0

    # Add the largest k elements to ans
    for i in range(k):
        ans += l[n - 1 - i]

    # Output the result
    print(ans)

# Call the main function
main()
