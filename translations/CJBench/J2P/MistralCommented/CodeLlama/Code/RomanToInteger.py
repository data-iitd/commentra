
import sys

# A map storing the Roman symbols and their corresponding integer values.
ROMAN_TO_INT = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

def roman_symbol_to_int(symbol):
    """
    Converts a single Roman symbol to its corresponding integer value.

    :param symbol: the Roman symbol to convert
    :return: the integer value of the given Roman symbol
    :raises ValueError: if the given symbol is unknown
    """
    try:
        return ROMAN_TO_INT[symbol]
    except KeyError:
        raise ValueError("Unknown Roman symbol: " + symbol)

def roman_to_int(roman):
    """
    Converts a string of Roman numerals to its corresponding integer value.

    :param roman: the Roman numeral string to convert
    :return: the integer value of the given Roman numeral string
    """
    if roman is None:  # Check if the input is None
        raise ValueError("Input cannot be None")

    roman = roman.upper()  # Convert the input to uppercase
    sum = 0  # Initialize the sum variable
    max_prev_value = 0  # Initialize the maximum previous value variable

    # Iterate through the Roman numeral string from the end to the beginning
    for i in range(len(roman) - 1, -1, -1):
        current_value = roman_symbol_to_int(roman[i])  # Get the integer value of the current Roman symbol
        if current_value >= max_prev_value:  # If the current value is greater than or equal to the maximum previous value
            sum += current_value  # Add the current value to the sum
            max_prev_value = current_value  # Update the maximum previous value
        else:  # Otherwise, subtract the current value from the sum
            sum -= current_value

    return sum  # Return the final integer value

def main():
    """
    The entry point of the program.
    """
    try:
        roman_numeral = sys.stdin.readline().strip()  # Read a line of input from the user
        result = roman_to_int(roman_numeral)  # Convert the Roman numeral to an integer
        print("Integer value: " + str(result))  # Print the integer value to the console
    except ValueError as e:  # Catch any exceptions thrown during the conversion process
        print("Error: " + str(e))  # Print the error message to the console

if __name__ == "__main__":
    main()

