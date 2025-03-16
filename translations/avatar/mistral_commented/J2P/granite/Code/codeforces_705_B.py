

import sys

def main():
    t = int(input())  # Reading the number of test cases
    arr = list(map(int, input().split()))  # Reading the input array

    prevWinner = 0  # Initializing the 'prevWinner' variable to 0

    for i in range(t):  # Iterating through the array
        if arr[i] == 1:  # Checking if the current element is 1
            if prevWinner == 0:  # If the previous winner was 0
                prevWinner = 2  # Update the 'prevWinner' variable to 2

            if (arr[i] - 1) % 2 == 0:  # Checking the parity of the current element's index
                print(prevWinner)  # Printing the output based on the 'prevWinner' value
                prevWinner = 2 if prevWinner == 1 else 1  # Updating the 'prevWinner' variable for the next iteration

    print("