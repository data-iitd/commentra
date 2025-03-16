import sys

def main():
    # Step 1: Read input values
    n = int(input())
    a = [int(x) for x in input().split()]

    # Step 2: Initialize a dynamic programming array
    dp = [-1] * (n + 1)

    # Step 3: Fill the dynamic programming array
    dp[n - 1] = a[n - 1]
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])

    # Step 4: Calculate the result
    for i in range(n):
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        else:
            print(dp[i + 1] - a[i] + 1, end=' ')

    # Step 5: Print the result
    print()

if __name__ == '__main__':
    main()

