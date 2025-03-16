






class RomanConverter:
    # Initializes a dictionary for Roman numerals to their integer values
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
        if roman is None:
            raise ValueError("Input cannot be null")
        roman = roman.upper()  # Converts the input string to uppercase
        sum = 0
        max_prev_value = 0
        for char in reversed(roman):
            current_value = RomanConverter.roman_symbol_to_int(char)
            if current_value >= max_prev_value:
                sum += current_value
                max_prev_value = current_value
            else:
                sum -= current_value
        return sum

# Main function to handle user input and output
if __name__ == "__main__":
    roman_numeral = input()
    try:
        result = RomanConverter.roman_to_int(roman_numeral)
        print(f"Integer value: {result}")
    except ValueError as e:
        print(f"Error: {e}")

# <END-OF-CODE>




