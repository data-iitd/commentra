class RomanConverter:
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
        if symbol not in RomanConverter.ROMAN_TO_INT:
            raise ValueError(f"Unknown Roman symbol: {symbol}")
        return RomanConverter.ROMAN_TO_INT[symbol]

    @staticmethod
    def roman_to_int(roman):
        if roman is None:
            raise ValueError("Input cannot be null")

        roman = roman.upper()
        sum_value = 0
        max_prev_value = 0
        for char in reversed(roman):
            current_value = RomanConverter.roman_symbol_to_int(char)
            if current_value >= max_prev_value:
                sum_value += current_value
                max_prev_value = current_value
            else:
                sum_value -= current_value

        return sum_value


if __name__ == "__main__":
    roman_numeral = input("Enter a Roman numeral: ")

    try:
        result = RomanConverter.roman_to_int(roman_numeral)
        print(f"Integer value: {result}")
    except ValueError as e:
        print(f"Error: {e}")

# <END-OF-CODE>
