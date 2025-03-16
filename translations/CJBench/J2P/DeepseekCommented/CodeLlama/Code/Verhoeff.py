import re // Importing re module for regular expressions

def verhoeff_check(digits): // Defining the verhoeff_check function
    if not re.match(r'^\d+$', digits): // Check if the input is valid
        raise ValueError("Input contains invalid characters: " + digits) // Raise an exception if the input is invalid
    multiplication_table = [ // Multiplication table for the Verhoeff algorithm
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
    multiplicative_inverse = [ // Multiplicative inverse table for the Verhoeff algorithm
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    ]
    permutation_table = [ // Permutation table for the Verhoeff algorithm
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 5, 7, 6, 2, 8, 3, 0, 9, 4],
        [5, 8, 0, 3, 7, 9, 6, 1, 4, 2],
        [8, 9, 1, 6, 0, 4, 3, 5, 2, 7],
        [9, 4, 5, 3, 1, 2, 6, 8, 7, 0],
        [4, 2, 8, 6, 5, 7, 3, 9, 0, 1],
        [2, 7, 9, 3, 8, 0, 6, 4, 1, 5],
        [7, 0, 4, 6, 9, 1, 3, 2, 5, 8]
    ]
    checksum = 0 // Initialize checksum to 0
    for i in range(len(digits) - 1, -1, -1): // Iterate over the digits in the input string
        index = len(digits) - i - 1 // Calculate the index for the permutation table
        b = permutation_table[i % 8][int(digits[index])] // Get the permuted value
        checksum = multiplication_table[checksum][b] // Update the checksum using the multiplication table
    return checksum == 0 // Return true if checksum is 0, otherwise false

def add_verhoeff_checksum(initial_digits): // Defining the add_verhoeff_checksum function
    if not re.match(r'^\d+$', initial_digits): // Check if the input is valid
        raise ValueError("Input contains invalid characters: " + initial_digits) // Raise an exception if the input is invalid
    modified_digits = initial_digits + "0" // Append "0" to the input string
    checksum = 0 // Initialize checksum to 0
    for i in range(len(modified_digits) - 1, -1, -1): // Iterate over the digits in the modified string
        index = len(modified_digits) - i - 1 // Calculate the index for the permutation table
        b = permutation_table[i % 8][int(modified_digits[index])] // Get the permuted value
        checksum = multiplication_table[checksum][b] // Update the checksum using the multiplication table
    checksum = multiplicative_inverse[checksum] // Get the multiplicative inverse of the checksum
    return initial_digits + str(checksum) // Return the input string with the appended checksum

if __name__ == "__main__": // Check if the script is being run directly
    import sys // Importing sys module for command line arguments
    if len(sys.argv) == 2: // Check if the script is being run with one argument
        input_to_validate = sys.argv[1] // Get the argument
        print("Input is " + ("valid" if verhoeff_check(input_to_validate) else "not valid")) // Validate the input and print the result
    elif len(sys.argv) == 3: // Check if the script is being run with two arguments
        input_to_generate_checksum = sys.argv[1] // Get the first argument
        print("Number with checksum: " + add_verhoeff_checksum(input_to_generate_checksum)) // Generate and print the checksum
    else: // If the script is being run with an invalid number of arguments
        print("Usage: python verhoeff.py <number to validate>") // Print the usage message
        print("Usage: python verhoeff.py <number to generate checksum>") // Print the usage message
    sys.exit(0) // Exit the script with a status code of 0

