# Import necessary libraries
import sys

def main():
    # Initialize sum and flag
    sum = 0
    flag = 0

    # Read a string from standard input
    x = input("Enter a string of digits separated by spaces or newline: ")

    while True:  # Begin an infinite loop
        # Initialize sum to zero before processing each string
        sum = 0

        # Process each character in the string 'x'
        for char in x:
            # Check if current character is end-of-string marker
            if char == '0' and len(x) == 1:
                # If so, print the sum of digits in the previous string and exit the loop
                print(f"Sum of digits in previous string: {sum}")
                return
            else:
                # Otherwise, add the integer value of the character to the sum
                sum += int(char)

        # Read next string from standard input
        x = input("Enter a string of digits separated by spaces or newline: ")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
