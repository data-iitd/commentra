# Import necessary libraries
import sys
from collections import defaultdict

# Constants
MOD = 10**9 + 7

# Main function
def main():
    # Input
    N, K = map(int, sys.stdin.readline().split())  # Read N and K
    A = list(map(int, sys.stdin.readline().split()))  # Read elements of array A

    # Solution
    ans1 = 0  # Initialize answer for the first part
    for i in range(N):  # Iterate through all elements in array A
        for j in range(N):  # Iterate through all other elements in array A
            if i >= j:
                continue  # Skip if current index is greater than or equal to the index of the inner loop
            if A[i] > A[j]:
                ans1 += 1  # Increment answer if the current element is greater than the inner element
                ans1 %= MOD  # Update answer modulo 1e9+7 to avoid overflow

    count = [0] * 2005  # Initialize an array to store the count of each unique element in array A
    for i in range(N):  # Iterate through all elements in array A
        count[A[i] - 1] += 1  # Increment the count of the current element in the count array

    ans2 = 0  # Initialize answer for the second part
    remain = N  # Initialize the remaining number of elements to be paired
    for i in range(2005):  # Iterate through all unique elements in array A
        remain -= count[i]  # Decrement the remaining number of elements to be paired for the current unique element
        ans2 += count[i] * remain  # Calculate the contribution of the current unique element to the answer

    ans = 0  # Initialize the final answer
    tmp = K * (K - 1) // 2  # Calculate (K*(K-1)) // 2 to get the number of unique pairs that can be formed using K elements
    tmp %= MOD  # Update the temporary variable modulo 1e9+7
    tmp *= ans2  # Multiply the temporary variable with the answer for the second part
    tmp %= MOD  # Update the temporary variable modulo 1e9+7
    ans += ans1 * K  # Add the answer for the first part multiplied by K to the final answer
    ans %= MOD  # Update the final answer modulo 1e9+7
    ans += tmp  # Add the temporary variable to the final answer
    ans %= MOD  # Update the final answer modulo 1e9+7

    # Output
    print(ans)  # Print the final answer

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
