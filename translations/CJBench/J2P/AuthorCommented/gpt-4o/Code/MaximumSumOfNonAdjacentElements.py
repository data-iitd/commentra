class Main:
    @staticmethod
    def get_max_sum_approach1(arr):
        if len(arr) == 0:
            return 0  # Check for empty array

        n = len(arr)
        dp = [0] * n

        # Base case: Maximum sum if only one element is present.
        dp[0] = arr[0]

        for ind in range(1, n):
            # Case 1: Do not take the current element, carry forward the previous max sum.
            not_take = dp[ind - 1]
            # Case 2: Take the current element, add it to the max sum up to two indices before.
            take = arr[ind]
            if ind > 1:
                take += dp[ind - 2]
            # Store the maximum of both choices in the dp array.
            dp[ind] = max(take, not_take)

        return dp[n - 1]

    @staticmethod
    def get_max_sum_approach2(arr):
        if len(arr) == 0:
            return 0  # Check for empty array

        n = len(arr)
        # Two variables to keep track of previous two results:
        # prev1 = max sum up to the last element (n-1)
        # prev2 = max sum up to the element before last (n-2)

        prev1 = arr[0]
        prev2 = 0

        for ind in range(1, n):
            # Case 1: Do not take the current element, keep the last max sum.
            not_take = prev1

            # Case 2: Take the current element and add it to the result from two steps back.
            take = arr[ind]
            if ind > 1:
                take += prev2

            # Calculate the current maximum sum and update previous values.
            current = max(take, not_take)

            # Shift prev1 and prev2 for the next iteration.
            prev2 = prev1
            prev1 = current

        return prev1

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))

    choice = int(input())

    if choice == 1:
        result = Main.get_max_sum_approach1(array)
    else:
        result = Main.get_max_sum_approach2(array)

    print("The maximum sum of non-adjacent elements is:", result)

# <END-OF-CODE>
