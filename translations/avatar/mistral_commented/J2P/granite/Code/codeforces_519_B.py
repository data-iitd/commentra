
import sys

def main():
    # Main method is the entry point of the Python application
    # It has a void return type and no parameters
    # We are using the sys.stdin and sys.stdout objects to read input from the standard input
    # and write the output to the standard output

    n = int(input())
    # Reading the number of test cases (n) from the input using the input() function and converting it to an integer

    a = 0
    b = 0
    c = 0
    # Declaring and initializing three integer variables a, b, and c with zero values

    for i in range(n):
        a += int(input())
    # Using a for loop to read and sum up the first number in each test case using the input() function and converting it to an integer
    # and adding it to the variable 'a'

    for i in range(n - 1):
        b += int(input())
    # Using a for loop to read and sum up the second number in each test case (except the last one) using the input() function and converting it to an integer
    # and adding it to the variable 'b'

    for i in range(n - 2):
        c += int(input())
    # Using a for loop to read and sum up the third number in each test case (except the last two) using the input() function and converting it to an integer
    # and adding it to the variable 'c'

    x = a - b
    # Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

    y = b - c
    # Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

    print(x)
    print(y)
    # Printing the values of 'x' and 'y' to the standard output using the print() function

if __name__ == "__main__":
    main()
