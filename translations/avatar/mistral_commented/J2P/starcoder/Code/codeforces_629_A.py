# Importing necessary packages
import sys

# Declaring the main function
def main():

    # Reading the number of strings 'num' from the user input
    num = int(input())

    # Initializing an empty list 'arr' with a size equal to 'num'
    arr = []

    # Reading each string's' from the user input and adding it to the list 'arr'
    for i in range(num):
        s = input()
        arr.append(s)

    # Initializing two variables 'counter' and 'fine'
    counter = 0
    fine = 0

    # The first nested loop to iterate through each character in each string
    for i in range(num):
        for k in range(num):
            # Checking if the character at position (i,k) in the string at index 'i' is 'C'
            if arr[i][k] == 'C':
                # Incrementing the counter variable
                counter += 1
        # Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) // 2
        # Resetting the counter variable for the next string
        counter = 0

    # The second nested loop to iterate through each character in each string again
    for i in range(num):
        for k in range(num):
            # Checking if the character at position (i,k) in the string at index 'k' is 'C'
            if arr[k][i] == 'C':
                # Incrementing the counter variable
                counter += 1
        # Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) // 2
        # Resetting the counter variable for the next string
        counter = 0

    # Printing the final result 'fine'
    print(fine)

# Calling the main function
if __name__ == '__main__':
    main()

