
import sys

# Multiplication table for the Main algorithm
MULTIPLICATION_TABLE = [
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 0, 6, 7, 8, 9, 5],
    [2, 3, 4, 0, 1, 7, 8, 9, 5, 6],
    [3, 4, 0, 1, 2, 8, 9, 5, 6, 7],
    [4, 0, 1, 2, 3, 9, 5, 6, 7, 8],
    [5, 9, 8, 7, 6, 0, 4, 3, 2, 1],
    [6, 5, 9, 8, 7, 1, 0, 4, 3, 2],
    [7, 6, 5, 9, 8, 2, 1, 0, 4, 3],
    [8, 7, 6, 5, 9, 3, 2, 1, 0, 4],
    [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
]

# Multiplicative inverse table for the Main algorithm
MULTIPLICATIVE_INVERSE = [
    0, 4, 3, 2, 1, 5, 6, 7, 8, 9
]

# Permutation table for the Main algorithm
PERMUTATION_TABLE = [
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 5, 7, 6, 2, 8, 3, 0, 9, 4],
    [5, 8, 0, 3, 7, 9, 6, 1, 4, 2],
    [8, 9, 1, 6, 0, 4, 3, 5, 2, 7],
    [9, 4, 5, 3, 1, 2, 6, 8, 7, 0],
    [4, 2, 8, 6, 5, 7, 3, 9, 0, 1],
    [2, 7, 9, 3, 8, 0, 6, 4, 1, 5],
    [7, 0, 4, 6, 9, 1, 3, 2, 5, 8]
]

# Main method to check if the input string is valid according to the Main algorithm
def verhoeff_check(digits):
    if not digits.isdigit(): # Check if the input is valid
        raise ValueError("Input contains invalid characters: " + digits)
    numbers = [int(digit) for digit in digits] # Convert input string to an array of integers
    checksum = 0 # Initialize checksum to 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1 # Calculate the index for the permutation table
        b = PERMUTATION_TABLE[i % 8][numbers[index]] # Get the permuted value
        checksum = MULTIPLICATION_TABLE[checksum][b] # Update the checksum using the multiplication table
    return checksum == 0 # Return true if checksum is 0, otherwise false

# Method to add a checksum to the input string using the Main algorithm
def add_main_checksum(initial_digits):
    modified_digits = initial_digits + "0" # Append "0" to the input string
    numbers = [int(digit) for digit in modified_digits] # Convert the modified string to an array of integers
    checksum = 0 # Initialize checksum to 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1 # Calculate the index for the permutation table
        b = PERMUTATION_TABLE[i % 8][numbers[index]] # Get the permuted value
        checksum = MULTIPLICATION_TABLE[checksum][b] # Update the checksum using the multiplication table
    checksum = MULTIPLICATIVE_INVERSE[checksum] # Get the multiplicative inverse of the checksum
    return initial_digits + str(checksum) # Return the input string with the appended checksum

# Main method to interact with the user
def main():
    input_to_validate = input("Enter a number to validate: ") # Prompt the user to enter a number
    print("Input is " + ("valid" if verhoeff_check(input_to_validate) else "not valid")) # Validate the input and print the result
    input_to_generate_checksum = input("Enter a number to generate a checksum: ") # Prompt the user to enter a number
    print("Number with checksum: " + add_main_checksum(input_to_generate_checksum)) # Generate and print the checksum

if __name__ == "__main__":
    main() # Call the main method to start the program

