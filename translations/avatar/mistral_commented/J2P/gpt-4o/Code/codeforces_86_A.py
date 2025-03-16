# Importing the necessary libraries
import sys

def power(a):
    # Function to calculate the number of digits in a number
    res = 0  # Initializing the result variable to 0
    while a > 0:  # While the number 'a' is greater than 0
        res += 1  # Increment the result variable
        a //= 10  # Divide the number by 10 to get the number of digits
    return res  # Return the result

def mult(a):
    # Function to calculate the product of a number with the maximum number that can be formed using its digits
    pow = power(a)  # Calculate the number of digits in 'a'
    max_num = 0  # Initializing the maximum variable to 0
    for j in range(pow):
        # Loop to calculate the maximum number that can be formed using the digits of the number 'a'
        max_num = max_num * 10 + 9  # Multiply the maximum variable with 10 and add 9 to get the next digit
    return a * (max_num - a)  # Return the product of the number 'a' and the maximum number calculated above

def main():
    # Main function definition
    l = int(input())  # Reading the first number 'l' from the console
    r = int(input())  # Reading the second number 'r' from the console

    res = 0  # Initializing the result variable to 0
    maxxes = [0] * 10  # Creating a list 'maxxes' of size 10 to store the maximum numbers that can be formed using each digit

    temp = 0  # Initializing a temporary variable to 0

    for i in range(10):  # Loop to calculate and store the maximum numbers that can be formed using each digit
        temp = temp * 10 + 9  # Multiply the temporary variable with 10 and add 9 to get the next digit
        maxxes[i] = (temp // 2) * (temp - temp // 2)  # Calculate and store the maximum number in the 'i'th index of the 'maxxes' list

    res = max(mult(l), res)  # Calculate the product of the first number 'l' with the maximum number that can be formed using its digits and update the result variable
    res = max(mult(r), res)  # Calculate the product of the second number 'r' with the maximum number that can be formed using its digits and update the result variable

    temp = 0  # Resetting the temporary variable to 0

    for i in range(10):  # Loop to check if the range between the first and second number includes the maximum number that can be formed using the 'i'th digit
        temp = temp * 10 + 9  # Multiply the temporary variable with 10 and add 9 to get the next digit
        if l <= temp // 2 <= r:  # Check if the range includes the maximum number that can be formed using the 'i'th digit
            res = max(maxxes[i], res)  # Update the result variable with the maximum number that can be formed using the 'i'th digit if the condition is true

    print(res)  # Printing the final result

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
