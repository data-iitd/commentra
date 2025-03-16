import sys  # Importing required module for standard input

def main():
    n = int(input().strip())  # Reading the first line of input which contains the number of test cases

    if n == 1:
        print("Hello World")  # If the number of test cases is 1, print "Hello World"
    else:
        # If not, reading the next two lines of input which contain two integers
        num1, num2 = map(int, input().strip().split())  # Storing the two integers in variables 'num1' and 'num2'
        print(num1 + num2)  # Printing the sum of the two integers as output

if __name__ == "__main__":
    main()  # Calling the main function to execute the program

# <END-OF-CODE>
