def get_max_sum_approach1(arr):
    if len(arr) == 0:  # Base case: empty array returns 0
        return 0
    n = len(arr)  # Length of the array
    dp = [0] * n  # Array to store the maximum sum of non-adjacent elements ending at each index

    dp[0] = arr[0]  # The maximum sum of non-adjacent elements ending at index 0 is the first element itself

    for ind in range(1, n):  # Iterate through the array from index 1 to n-1
        not_take = dp[ind - 1]  # The maximum sum of non-adjacent elements ending at index ind-1
        take = arr[ind]  # The element at index ind
        if ind > 1:  # If we can take the element at index ind-2
            take += dp[ind - 2]  # Add the maximum sum of non-adjacent elements ending at index ind-2
        dp[ind] = max(take, not_take)  # Update the maximum sum of non-adjacent elements ending at index ind
    return dp[-1]  # The maximum sum of non-adjacent elements ending at the last index


def get_max_sum_approach2(arr):
    if len(arr) == 0:  # Base case: empty array returns 0
        return 0
    n = len(arr)  # Length of the array
    prev1 = arr[0]  # Initialize the previous two maximum sums
    prev2 = 0

    for ind in range(1, n):  # Iterate through the array from index 1 to n-1
        not_take = prev1  # The maximum sum of non-adjacent elements ending at the previous index
        take = arr[ind]  # The element at the current index
        if ind > 1:  # If we can take the element at index ind-1
            take += prev2  # Add the maximum sum of non-adjacent elements ending at index ind-1
        current = max(take, not_take)  # Update the maximum sum of non-adjacent elements at the current index
        prev2 = prev1  # Update the previous maximum sum
        prev1 = current  # Update the current maximum sum
    return prev1  # The maximum sum of non-adjacent elements at the last index


# Main method to read input and call the appropriate method based on user choice
def main():
    n = int(input())  # Read the number of elements in the array
    array = list(map(int, input().split()))  # Create a list to store the elements

    choice = int(input())  # Read the user choice to determine which method to call

    result = 0
    if choice == 1:  # If the user chooses the first method
        result = get_max_sum_approach1(array)
    else:  # If the user chooses the second method
        result = get_max_sum_approach2(array)

    print("The maximum sum of non-adjacent elements is:", result)  # Print the result to the console


main()
