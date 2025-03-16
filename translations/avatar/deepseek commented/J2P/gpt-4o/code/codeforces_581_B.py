import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    # Step 4: Read input values
    n = int(data[0])
    a = list(map(int, data[1:n+1]))

    # Step 5: Initialize a dynamic programming array
    dp = [-1] * (n + 1)

    # Step 6: Fill the dynamic programming array
    dp[n - 1] = a[n - 1]
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])

    # Step 7: Calculate the result
    result = []
    for i in range(n):
        if a[i] > dp[i + 1]:
            result.append(0)
        else:
            result.append(dp[i + 1] - a[i] + 1)

    # Step 8: Print the result
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
