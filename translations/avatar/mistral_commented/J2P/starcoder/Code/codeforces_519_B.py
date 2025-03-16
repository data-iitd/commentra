import sys

def main():
    # Main method is the entry point of the Python application
    # It has a void return type and a String array as its parameter
    # We are using the sys module to read input from the standard input
    # and the sys module to write the output to the standard output
    # We are also handling IOError to catch any I/O related errors

    n = int(sys.stdin.readline())
    # Reading the number of test cases (n) from the input using the readline() method of the sys module

    a = 0
    b = 0
    c = 0
    # Declaring and initializing three integer variables a, b, and c with zero values

    for i in range(n):
        a += int(sys.stdin.readline())
        # Using a for loop to read and sum up the first number in each test case using the readline() method of the sys module
        # and adding it to the variable 'a'

    for i in range(n-1):
        b += int(sys.stdin.readline())
        # Using a for loop to read and sum up the second number in each test case (except the last one) using the readline() method of the sys module
        # and adding it to the variable 'b'

    for i in range(n-2):
        c += int(sys.stdin.readline())
        # Using a for loop to read and sum up the third number in each test case (except the last two) using the readline() method of the sys module
        # and adding it to the variable 'c'

    x = a - b
    # Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

    y = b - c
    # Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

    print(x)
    print(y)
    # Printing the values of 'x' and 'y' to the standard output using the print() function of the sys module

if __name__ == "__main__":
    main()
# Calling the main() function to start the execution of the program

