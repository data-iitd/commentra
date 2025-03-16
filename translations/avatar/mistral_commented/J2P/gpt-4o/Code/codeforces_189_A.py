# Importing the necessary module
import sys

def main():
    n = int(input())  # Reading the number of elements in the array from the console
    maxn = 4010  # Defining the maximum size of the dynamic programming array

    # Reading the three integers representing the array elements
    a = int(input())
    b = int(input())
    c = int(input())

    # Defining a list to store the array elements
    arr = [a, b, c]

    dp = [-float('inf')] * maxn  # Creating a dynamic programming list of size maxn

    # Initializing the dynamic programming array with minimum values
    for i in range(n):
        dp[i] = -float('inf')  # Setting all elements to minimum value

    dp[0] = 0  # Setting the first element to 0

    # Filling the dynamic programming array using two nested loops
    for i in range(3):  # Looping through the array elements
        for j in range(arr[i], len(dp)):  # Looping through the dynamic programming array
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)  # Updating the maximum length ending at j

    # Printing the result, which is the maximum length ending at the nth index
    print(dp[n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
