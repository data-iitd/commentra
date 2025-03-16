import math  # Importing the math module for logarithmic and power functions

def main():  # Defining the main function
    q = int(input())  # Reading the number of test cases from the console

    for _ in range(q):  # Starting a for loop that runs q times
        n = int(input())  # Reading the integer 'n' from the console

        s = 0  # Initializing the variable 's' with zero value

        x = int(math.log(n, 2))  # Calculating the integer 'x' using the logarithmic formula
        x += 1  # Incrementing the value of 'x' by 1

        s = -1 * (2 ** x) + 2 + (n * (n + 1)) // 2 - (2 ** x)  # Calculating the value of 's' using the given formula

        print(s)  # Printing the value of 's' to the console

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
