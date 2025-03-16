# Import the necessary library
import sys

def main():
    while True:  # Infinite loop that continues until the user inputs "0"
        str_input = input()  # Read a string from the user
        if str_input == "0":  # If the input string is "0", break the loop
            break
        sum_digits = 0  # Initialize sum to 0
        for char in str_input:  # Loop through each character in the string
            num = int(char)  # Convert the character to an integer
            sum_digits += num  # Add the integer to the sum
        
        print(sum_digits)  # Print the sum

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
