import math  # Importing the math module for mathematical functions

# Main function where the execution of the program starts
def main():
    # Reading the first long integer input N
    N = int(input())

    # Initializing the minimum variable with the first input value
    min_value = None
    for i in range(5):
        current_value = int(input())  # Read the current input value
        if min_value is None:  # If it's the first iteration of the loop
            min_value = current_value  # Set the minimum value to the current input value
        else:  # Otherwise
            min_value = min(min_value, current_value)  # Update the minimum value if it's smaller

    # Printing the answer
    p(math.ceil(N / min_value) + 4)

# Utility function to print a value as output
def p(ans):
    print(ans)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
