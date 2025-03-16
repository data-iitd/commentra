# Import the sys module to read input
import sys

# Define the main function
def main():
    # Read the first integer input from the user
    a = int(input())
    
    # Read the second integer input from the user
    b = int(input())
    
    # Check if the first integer 'a' is positive
    if a > 0:
        # If 'a' is positive, print the message "Positive"
        print("Positive")
    
    # Else if the second integer 'b' is non-negative
    elif b >= 0:
        # If 'b' is non-negative, print the message "Zero"
        print("Zero")
    
    # Else if the difference between 'b' and 'a' is even
    elif (b - a + 1) % 2 == 0:
        # If the difference is even, print the message "Positive"
        print("Positive")
    
    # Else, print the message "Negative"
    else:
        print("Negative")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
