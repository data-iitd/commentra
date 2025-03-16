# Import the necessary module
from typing import List

# Declare the main function
def main():
    n = int(input())  # Read the size of the vector
    p = list(map(int, input().split()))  # Read elements of the vector p from the user

    # Initialize the answer variable ans to zero
    ans = 0

    # Check each element of the vector p starting from the first one
    for i in range(n - 1):  # Loop through each element except the last one
        if p[i] == i + 1:  # Check if the current element is equal to its index + 1
            p[i + 1] = p[i]  # Swap the current element with the next one if it is in the wrong position
            ans += 1  # Increment the answer if a swap was made

    # Check the last element of the vector p
    if p[n - 1] == n:  # Check if the last element is equal to its index + 1
        ans += 1  # Increment the answer if it is in the wrong position

    # Print the answer to the user
    print(ans)  # Output the answer

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
