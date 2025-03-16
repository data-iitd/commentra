
import re

# A map storing the Roman symbols and their corresponding integer values
ROMAN_TO_INT = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

# Converts a single Roman symbol to its corresponding integer value
def romanSymbolToInt(symbol):
    return ROMAN_TO_INT.get(symbol, None)

# Converts a string of Roman numerals to its corresponding integer value
def romanToInt(roman):
    if roman is None: # Check if the input is null
        raise ValueError("Input cannot be null")
    roman = roman.upper() # Convert the input to uppercase
    sum = 0 # Initialize the sum variable
    maxPrevValue = 0 # Initialize the maximum previous value variable

    # Iterate through the Roman numeral string from the end to the beginning
    for i in range(len(roman) - 1, -1, -1):
        currentValue = romanSymbolToInt(roman[i]) # Get the integer value of the current Roman symbol
        if currentValue >= maxPrevValue: # If the current value is greater than or equal to the maximum previous value
            sum += currentValue # Add the current value to the sum
            maxPrevValue = currentValue # Update the maximum previous value
        else: # Otherwise, subtract the current value from the sum
            sum -= currentValue

    return sum # Return the final integer value

# The entry point of the program
if __name__ == '__main__':
    romanNumeral = input() # Read a line of input from the user

    try:
        result = romanToInt(romanNumeral) # Convert the Roman numeral to an integer
        print("Integer value: " + str(result)) # Print the integer value to the console
    except ValueError as e: # Catch any exceptions thrown during the conversion process
        print("Error: " + e.args[0]) # Print the error message to the console

