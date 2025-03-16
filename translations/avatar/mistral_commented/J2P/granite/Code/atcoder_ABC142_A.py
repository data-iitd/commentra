

import sys # Import sys for handling input and output

try: # Begin try block for handling normal input and calculation
    input = float(sys.stdin.readline()) # Read input from standard input and parse it as a float

    # Calculate the number of odd numbers in the input
    countOdd = round(input / 2)

    # Print the result
    print(countOdd / input)
except ValueError: # Begin except block for handling value errors
    print("Error: Invalid input") # Print an error message if the input is not a valid number
except Exception as e: # Begin except block for handling other exceptions
    print("Error:", str(e)) # Print an error message with the exception message if an unexpected error occurs