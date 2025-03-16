

def max_sum_non_adjacent(arr):
    if len(arr) == 0:
        return 0  # Check for empty array

    n = len(arr)
    dp = [0] * n

    # Base case: Maximum sum if only one element is present.
    dp[0] = arr[0]

    for ind in range(1, n):
        # Case 1: Do not take the current element, carry forward the previous max
        # sum.
        not_take = dp[ind - 1]
        # Case 2: Take the current element, add it to the max sum up to two
        # indices before.
        take = arr[ind]
        if ind > 1:
            take += dp[ind - 2]
        # Store the maximum of both choices in the dp array.
        dp[ind] = max(take, not_take)

    return dp[n - 1]

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    choice = int(input())

    result = max_sum_non_adjacent(array)

    print(f"The maximum sum of non-adjacent elements is: {result}")

Translate the above Python code to JavaScript and end with comment "