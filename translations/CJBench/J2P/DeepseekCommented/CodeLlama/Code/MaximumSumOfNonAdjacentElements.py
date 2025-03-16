import math
import sys

# Method to calculate the maximum sum of non-adjacent elements using dynamic programming
def get_max_sum_approach1(arr):
    if len(arr) == 0:
        return 0  # Return 0 if the array is empty
    n = len(arr)
    dp = [0] * n
    dp[0] = arr[0]  # Initialize the first element of dp array
    for ind in range(1, n):
        not_take = dp[ind - 1]  # Value if we don't take the current element
        take = arr[ind]  # Value if we take the current element
        if ind > 1:
            take += dp[ind - 2]  # Add the value from two indices back if possible
        dp[ind] = max(take, not_take)  # Choose the maximum of take or notTake
    return dp[n - 1]  # Return the last element of dp array which contains the result


# Method to calculate the maximum sum of non-adjacent elements using a space-efficient approach
def get_max_sum_approach2(arr):
    if len(arr) == 0:
        return 0  # Return 0 if the array is empty
    n = len(arr)
    prev1 = arr[0]  # Store the value of the first element
    prev2 = 0  # Initialize the second previous value
    for ind in range(1, n):
        not_take = prev1  # Value if we don't take the current element
        take = arr[ind]  # Value if we take the current element
        if ind > 1:
            take += prev2  # Add the value from two indices back if possible
        current = max(take, not_take)  # Choose the maximum of take or notTake
        prev2 = prev1  # Update the second previous value
        prev1 = current  # Update the previous value
    return prev1  # Return the last updated previous value which contains the result


# Main method to run the program
def main():
    n = int(sys.stdin.readline())  # Read the size of the array
    array = list(map(int, sys.stdin.readline().split()))
    choice = int(sys.stdin.readline())  # Read the choice of the method
    result = 0
    if choice == 1:
        result = get_max_sum_approach1(array)  # Calculate the result using method 1
    else:
        result = get_max_sum_approach2(array)  # Calculate the result using method 2
    print("The maximum sum of non-adjacent elements is: " + str(result))  # Print the result


if __name__ == "__main__":
    main()


