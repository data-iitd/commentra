# Importing the sys module for reading input
import sys

# Defining the main function
def main():
    # Reading the number of test cases
    n = int(sys.stdin.readline().strip())

    # Declaring a list dp of size 200001 to store the position of each number in the sequence
    dp = [0] * 200001

    # Initializing a variable ans to store the answer
    ans = 0

    # Iterating through each test case
    for i in range(n):
        # Reading the next number to be added to the sequence
        num = int(sys.stdin.readline().strip())

        # Storing the position of the number in the dp list
        dp[num] = i

    # Calculating the answer by iterating through the dp list and finding the absolute difference between the positions of consecutive numbers
    for i in range(2, n + 1):
        # Adding the absolute difference to the answer
        ans += abs(dp[i] - dp[i - 1])

    # Printing the answer to the console
    print(ans)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
