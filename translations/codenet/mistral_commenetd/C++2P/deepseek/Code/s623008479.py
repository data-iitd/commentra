# Include the necessary libraries
from typing import List

# Define the main function
def main():
    # Read the number of elements and the size of the subarray from the user
    n, k = map(int, input().split())

    # Read the elements of the vector from the user
    l = list(map(int, input().split()))

    # Sort the vector in ascending order
    l.sort()

    # Initialize the sum variable to 0
    ans = 0

    # Iterate through the first k elements in descending order and add their values to the sum
    for i in range(k):
        ans += l[n - 1 - i]

    # Output the value of the sum to the console
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()
