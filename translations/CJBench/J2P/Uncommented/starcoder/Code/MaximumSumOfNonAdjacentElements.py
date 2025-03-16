
import sys

def getMaxSumApproach1(arr):
    if len(arr) == 0:
        return 0
    n = len(arr)
    dp = [0] * n
    dp[0] = arr[0]
    for ind in range(1, n):
        notTake = dp[ind - 1]
        take = arr[ind]
        if ind > 1:
            take += dp[ind - 2]
        dp[ind] = max(take, notTake)
    return dp[n - 1]

def getMaxSumApproach2(arr):
    if len(arr) == 0:
        return 0
    n = len(arr)
    prev1 = arr[0]
    prev2 = 0
    for ind in range(1, n):
        notTake = prev1
        take = arr[ind]
        if ind > 1:
            take += prev2
        current = max(take, notTake)
        prev2 = prev1
        prev1 = current
    return prev1

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    array = [int(sys.stdin.readline()) for _ in range(n)]
    choice = int(sys.stdin.readline())
    result = getMaxSumApproach1(array) if choice == 1 else getMaxSumApproach2(array)
    print("The maximum sum of non-adjacent elements is: " + str(result))

