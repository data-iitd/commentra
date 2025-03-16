# Importing the 'sys' module for input/output operations
import sys

def main():
    # Reading input values for variables a, b, c, and x from the user
    a, b, c, x = map(int, sys.stdin.readline().split())

    # Initializing a variable to count the number of combinations
    sum = 0

    # Using nested loops to iterate through the possible combinations of i, j, and k
    for i in range(a + 1):  # for i from 0 to a
        for j in range(b + 1):  # for j from 0 to b
            for k in range(c + 1):  # for k from 0 to c
                # Checking if the sum of i, j, and k multiplied by 500, 100, and 50 respectively equals x
                if 500 * i + 100 * j + 50 * k == x:
                    sum += 1  # Incrementing the sum variable if the condition is true

    # Printing the final value of sum to the console
    print(sum)

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
