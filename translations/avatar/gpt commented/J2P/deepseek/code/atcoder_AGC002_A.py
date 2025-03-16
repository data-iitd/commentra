# Importing the Scanner class for user input (in Python, we use the built-in input function)

def main():
    # Reading two integer values from the user
    a = int(input())
    b = int(input())
    
    # Checking if the first integer 'a' is positive
    if a > 0:
        print("Positive") # Output "Positive" if 'a' is greater than 0
    # Checking if the second integer 'b' is non-negative (zero or positive)
    elif b >= 0:
        print("Zero") # Output "Zero" if 'b' is greater than or equal to 0
    # Checking if the difference between 'b' and 'a' plus 1 is even
    elif (b - a + 1) % 2 == 0:
        print("Positive") # Output "Positive" if the result is even
    # If none of the above conditions are met, it means the result is negative
    else:
        print("Negative") # Output "Negative" for all other cases

# Calling the main function
if __name__ == "__main__":
    main()
