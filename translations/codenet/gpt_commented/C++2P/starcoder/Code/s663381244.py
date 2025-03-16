# Disable synchronization with C I/O for faster input/output
import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

# Initialize a list to hold the denominations of money
m = [10, 50, 100, 500]

# Read money input until EOF or invalid input
for money in map(int, raw_input().split()):
    # Print a newline before the output of subsequent transactions
    if money:
        if not first:
            print
        first = False

        # Initialize sum to calculate total value of coins
        sum = 0
        # Initialize a list to hold the number of each denomination
        num = [0, 0, 0, 0]

        # Read the number of coins for each denomination and calculate the total sum
        for i in range(4):
            num[i] = int(raw_input())
            sum += num[i] * m[i]

        # Calculate the change to be returned
        change = sum - money

        # Calculate how many coins of each denomination to return as change
        for i in range(3, -1, -1):
            if change / m[i]:
                num[i] -= change / m[i]
                change %= m[i]

        # Output the remaining coins of each denomination that are greater than zero
        for i in range(4):
            if num[i] > 0:
                print m[i], num[i]

# 