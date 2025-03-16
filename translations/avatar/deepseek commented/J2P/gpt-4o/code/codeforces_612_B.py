# Importing the sys module for input
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the integer n from the input
    dp = [0] * 200001  # Initializing a list to store positions

    # Storing positions of the integers in the list dp
    for i in range(n):
        dp[int(sys.stdin.readline().strip())] = i

    ans = 0  # Initializing the answer variable to 0

    # Calculating the sum of absolute differences between consecutive positions
    for i in range(2, n + 1):
        ans += abs(dp[i] - dp[i - 1])

    print(ans)  # Printing the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
