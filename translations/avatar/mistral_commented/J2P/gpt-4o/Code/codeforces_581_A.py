# Importing the necessary module for reading input
import sys

def main():  # Defining the main function
    a = int(input())  # Reading the first integer input and assigning it to variable a
    b = int(input())  # Reading the second integer input and assigning it to variable b

    count = 0  # Initializing the count variable to 0

    while True:  # Starting an infinite loop
        if a > 0 and b > 0:  # Checking if both a and b are greater than 0
            count += 1  # Incrementing the count variable if both conditions are true
            a -= 1  # Decrementing the value of variable a by 1
            b -= 1  # Decrementing the value of variable b by 1
        else:  # If either a or b is not greater than 0
            break  # Exiting the loop

    ans = a // 2 + b // 2  # Calculating the answer by dividing each number by 2 and summing the results

    print(count, ans)  # Printing the count and answer to the console

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
