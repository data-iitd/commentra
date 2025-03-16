import re

# A static map to hold the Roman numeral symbols and their corresponding integer values
ROMAN_TO_INT = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

# Converts a single Roman numeral character to its integer value
def romanSymbolToInt(symbol):
    return ROMAN_TO_INT.get(symbol, None)

# Converts a Roman numeral string to its integer value
def romanToInt(roman):
    # Check for null input and throw an exception if it is null
    if roman is None:
        raise Exception("Input cannot be null")
    # Convert the input string to uppercase to handle lowercase inputs
    roman = roman.upper()
    sum = 0 # Variable to hold the final integer value
    maxPrevValue = 0 # Variable to track the maximum value of the previous Roman numeral

    # Iterate through the Roman numeral string from right to left
    for i in range(len(roman) - 1, -1, -1):
        currentValue = romanSymbolToInt(roman[i]) # Get the integer value of the current Roman numeral
        # If the current value is greater than or equal to the maximum previous value, add it to the sum
        if currentValue >= maxPrevValue:
            sum += currentValue
            maxPrevValue = currentValue # Update the maximum previous value
        else:
            # If the current value is less than the maximum previous value, subtract it from the sum
            sum -= currentValue
    return sum # Return the final computed integer value

# Main method to execute the program
if __name__ == '__main__':
    romanNumeral = input("Enter a Roman numeral: ") # Read the input Roman numeral from the user
    try:
        # Convert the Roman numeral to an integer and print the result
        result = romanToInt(romanNumeral)
        print("Integer value: " + str(result))
    except Exception as e:
        # Handle exceptions and print error messages
        print("Error: " + str(e))

