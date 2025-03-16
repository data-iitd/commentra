import sys  # Importing sys for input/output
from collections import defaultdict  # Importing defaultdict for easier dictionary handling

def main():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings

    n = int(data[0])  # Reading the number of elements in the array
    a = list(map(int, data[1:n+1]))  # Creating a list of size n to store the elements

    dp = [-1] * (n + 1)  # Creating a list of size n+1 to store the maximum subarray sum ending at each index
    dp[n - 1] = a[n - 1]  # Setting the last element of the dp list with the last element of the array

    for i in range(n - 1, -1, -1):  # Loop to calculate the maximum subarray sum ending at each index
        dp[i] = max(dp[i + 1], a[i])  # Update dp[i] with the maximum of dp[i + 1] and a[i]

    result = []  # List to store the results for each test case
    for i in range(n):  # Loop to compute the answer for each element
        if a[i] > dp[i + 1]:  # If the current element is greater than the maximum subarray sum ending at the next index
            result.append(0)  # Append 0 as the answer
        else:
            result.append(dp[i + 1] - a[i] + 1)  # Else append the length of the subarray ending at the current index

    print(" ".join(map(str, result)))  # Print the results as a space-separated string

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
