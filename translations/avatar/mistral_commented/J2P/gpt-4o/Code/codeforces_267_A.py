# Importing the necessary module for user input
import sys

def main():  # Defining the main function
    n = int(sys.stdin.readline().strip())  # Reading the number of test cases from the user

    for _ in range(n):  # Iterating through each test case
        a = int(sys.stdin.readline().strip())  # Reading the first number from the user
        b = int(sys.stdin.readline().strip())  # Reading the second number from the user
        print(sub(a, b))  # Printing the result of subtracting 'b' from 'a'

def sub(a, b):  # Defining the sub function for subtracting two numbers
    min_val = min(a, b)  # Finding the smaller number
    max_val = max(a, b)  # Finding the larger number
    result = 0  # Initializing the result variable

    while min_val > 0:  # Iterating as long as the smaller number is greater than zero
        result += max_val // min_val  # Adding the quotient of the larger number divided by the smaller number to the result
        max_val = max_val % min_val  # Updating the larger number by taking the remainder of the larger number with the smaller number
        curr_min = min(min_val, max_val)  # Finding the current smaller number
        curr_max = max(min_val, max_val)  # Finding the current larger number
        min_val = curr_min  # Updating the smaller number
        max_val = curr_max  # Updating the larger number

    return result  # Returning the final result

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
