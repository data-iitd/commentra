
import re

# Initializes a map for Roman numerals to their integer values
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

# Converts a full Roman numeral string to an integer
def romanToInt(roman):
    if roman is None:
        raise ValueError("Input cannot be null")
    roman = roman.upper() # Converts the input string to uppercase
    sum = 0
    maxPrevValue = 0
    for i in range(len(roman) - 1, -1, -1):
        currentValue = romanSymbolToInt(roman[i])
        if currentValue >= maxPrevValue:
            sum += currentValue
            maxPrevValue = currentValue
        else:
            sum -= currentValue
    return sum

# Main method to handle user input and output
def main():
    romanNumeral = input()
    try:
        result = romanToInt(romanNumeral)
        print("Integer value: " + str(result))
    except ValueError as e:
        print("Error: " + e.args[0])

if __name__ == "__main__":
    main()

