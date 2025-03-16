class RomanConverter:
    # A static dictionary to hold the Roman numeral symbols and their corresponding integer values
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
        # Converts a single Roman numeral character to its integer value
        if symbol not in RomanConverter.ROMAN_TO_INT:
            raise ValueError(f"Unknown Roman symbol: {symbol}")
        return RomanConverter.ROMAN_TO_INT[symbol]

    @staticmethod
    def roman_to_int(roman):
        # Converts a Roman numeral string to its integer value
        if roman is None:
            raise ValueError("Input cannot be null")
        
        roman = roman.upper()  # Convert the input string to uppercase to handle lowercase inputs
        sum_value = 0  # Variable to hold the final integer value
        max_prev_value = 0  # Variable to track the maximum value of the previous Roman numeral

        # Iterate through the Roman numeral string from right to left
        for char in reversed(roman):
            current_value = RomanConverter.roman_symbol_to_int(char)  # Get the integer value of the current Roman numeral
            # If the current value is greater than or equal to the maximum previous value, add it to the sum
            if current_value >= max_prev_value:
                sum_value += current_value
                max_prev_value = current_value  # Update the maximum previous value
            else:
                # If the current value is less than the maximum previous value, subtract it from the sum
                sum_value -= current_value
        
        return sum_value  # Return the final computed integer value


# Main execution block
if __name__ == "__main__":
    roman_numeral = input()  # Read the input Roman numeral from the user
    try:
        # Convert the Roman numeral to an integer and print the result
        result = RomanConverter.roman_to_int(roman_numeral)
        print(f"Integer value: {result}")
    except ValueError as e:
        # Handle exceptions and print error messages
        print(f"Error: {e}")

# <END-OF-CODE>
