import sys

def main():
    # Step 4: Read input values
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))

    # Step 5: Initialize a dynamic programming array
    dp = [-1] * (n + 1)

    # Step 6: Fill the dynamic programming array
    dp[n - 1] = a[n - 1]
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])

    # Step 7: Calculate the result
    for i in range(n):
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        else:
            print(dp[i + 1] - a[i] + 1, end=' ')

    # Step 8: Print the result
    print()

if __name__ == '__main__':
    main()

# Step 9: Debugging (optional)
# debug(obj1, obj2, ...)

