class Main:
    @staticmethod
    def get_max_sum_approach1(arr):
        if len(arr) == 0:
            return 0
        n = len(arr)
        dp = [0] * n
        dp[0] = arr[0]
        for ind in range(1, n):
            not_take = dp[ind - 1]
            take = arr[ind]
            if ind > 1:
                take += dp[ind - 2]
            dp[ind] = max(take, not_take)
        return dp[n - 1]

    @staticmethod
    def get_max_sum_approach2(arr):
        if len(arr) == 0:
            return 0
        n = len(arr)
        prev1 = arr[0]
        prev2 = 0
        for ind in range(1, n):
            not_take = prev1
            take = arr[ind]
            if ind > 1:
                take += prev2
            current = max(take, not_take)
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
