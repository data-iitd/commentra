
import sys

def main():
    t = int(input()) # Read the number of test cases
    arr = list(map(int, input().split())) # Populate the array with input values

    prevWinner = 0 # Variable to track the previous winner

    for i in range(t):
        if arr[i] == 1: # Check if the current element is 1
            if prevWinner == 0: # If the previous winner is 0, set the previous winner to 2
                prevWinner = 2

        if prevWinner == 2 or prevWinner == 0: # Determine the winner based on the previous winner and the current element
            if (arr[i] - 1) % 2 == 0: # Check the parity of (arr[i] - 1)
                print(2) # Print winner 2
                prevWinner = 2 # Update previous winner
            else:
                print(1) # Print winner 1
                prevWinner = 1 # Update previous winner
        else:
            if (arr[i] - 1) % 2 == 0: # Check the parity of (arr[i] - 1)
                print(1) # Print winner 1
                prevWinner = 1 # Update previous winner
            else:
                print(2) # Print winner 2
                prevWinner = 2 # Update previous winner

    print("