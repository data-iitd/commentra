import sys ; // Importing the sys module for user input

def sub ( a, b ) : // Defining the sub function for subtracting two numbers
    min = min ( a, b ) ; // Finding the smaller number
    max = max ( a, b ) ; // Finding the larger number
    result = 0 ; // Initializing the result variable

    while min > 0 : // Iterating as long as the smaller number is greater than zero
        result += max // Adding the quotient of the larger number divided by the smaller number to the result
        max = max % min ; // Updating the larger number by taking the remainder of the larger number with the smaller number
        min = min ( min, max ) ; // Finding the current smaller number
        max = max ( min, max ) ; // Finding the current larger number

    return result ; // Returning the final result

if __name__ == '__main__' : // Defining the main function
    n = int ( sys.stdin.readline ( ) ) ; // Reading the number of test cases from the user

    for i in range ( n ) : // Iterating through each test case
        a = int ( sys.stdin.readline ( ) ) ; // Reading the first number from the user
        b = int ( sys.stdin.readline ( ) ) ; // Reading the second number from the user
        print ( sub ( a, b ) ) ; // Printing the result of subtracting 'b' from 'a'

