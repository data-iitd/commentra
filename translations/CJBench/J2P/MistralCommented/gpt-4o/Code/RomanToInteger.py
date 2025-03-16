class RomanConverter:
    """
    Class for converting Roman numerals to integers.
    """

    # A dictionary storing the Roman symbols and their corresponding integer values.
    ROMAN_TO_INT = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    @staticmethod
    def roman_symbol_to_int(symbol):
        """
        Converts a single Roman symbol to its corresponding integer value.

        :param symbol: The Roman symbol to convert
        :return: The integer value of the given Roman symbol
        :raises ValueError: If the given symbol is unknown
        """
        if symbol not in RomanConverter.ROMAN_TO_INT:
            raise ValueError(f"Unknown Roman symbol: {symbol}")
        return RomanConverter.ROMAN_TO_INT[symbol]

    @staticmethod
    def roman_to_int(roman):
        """
        Converts a string of Roman numerals to its corresponding integer value.

        :param roman: The Roman numeral string to convert
        :return: The integer value of the given Roman numeral string
        :raises ValueError: If the input is null or contains unknown symbols
        """
        if roman is None:  # Check if the input is None
            raise ValueError("Input cannot be null")
        
        roman = roman.upper()  # Convert the input to uppercase
        sum_value = 0  # Initialize the sum variable
        max_prev_value = 0  # Initialize the maximum previous value variable

        # Iterate through the Roman numeral string from the end to the beginning
        for char in reversed(roman):
            current_value = RomanConverter.roman_symbol_to_int(char)  # Get the integer value of the current Roman symbol
            if current_value >= max_prev_value:  # If the current value is greater than or equal to the maximum previous value
                sum_value += current_value  # Add the current value to the sum
                max_prev_value = current_value  # Update the maximum previous value
            else:  # Otherwise, subtract the current value from the sum
                sum_value -= current_value

        return sum_value  # Return the final integer value


if __name__ == "__main__":
    roman_numeral = input()  # Read a line of input from the user

    try:
        result = RomanConverter.roman_to_int(roman_numeral)  # Convert the Roman numeral to an integer
        print("Integer value:", result)  # Print the integer value to the console
    except ValueError as e:  # Catch any exceptions thrown during the conversion process
        print("Error:", e)  # Print the error message to the console

# <END-OF-CODE>
