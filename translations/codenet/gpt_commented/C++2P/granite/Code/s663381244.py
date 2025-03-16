
# Disable synchronization with C I/O for faster input/output
import os
import sys

# Initialize a list to hold the denominations of money
m = [10, 50, 100, 500]

first = True # Flag to handle formatting of output
# Read money input until EOF or invalid input
while True:
    money = input() # Read the money input
    if not money:
        break # Exit the loop if the input is empty

    # Print a newline before the output of subsequent transactions
    if not first:
        print()

    first = False # Set the flag to false after the first input
    sum = 0 # Initialize sum to calculate total value of coins
    num = [0, 0, 0, 0] # List to hold the number of each denomination

    # Read the number of coins for each denomination and calculate the total sum
    for i in range(4):
        num[i] = int(input()) # Input the number of coins for the current denomination
        sum += num[i] * m[i] # Update the total sum

    # Calculate the change to be returned
    change = sum - int(money)

    # Calculate how many coins of each denomination to return as change
    for i in range(3, -1, -1):
        if change // m[i]: # Check if the current denomination can be used for change
            num[i] = num[i] - change // m[i] # Reduce the number of coins of this denomination
            change %= m[i] # Update the remaining change to be returned

    # Output the remaining coins of each denomination that are greater than zero
    for i in range(4):
        if num[i] > 0: # Only print denominations that still have coins left
            print(m[i], num[i]) # Print denomination and count


