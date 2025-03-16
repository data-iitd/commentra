

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
def roman_symbol_to_int(symbol):
    return ROMAN_TO_INT.get(symbol, 0)

# Converts a full Roman numeral string to an integer
def roman_to_int(roman):
    if roman is None:
        raise ValueError("Input cannot be null")
    roman = roman.upper()  # Converts the input string to uppercase
    sum = 0
    max_prev_value = 0
    for i in range(len(roman) - 1, -1, -1):
        current_value = roman_symbol_to_int(roman[i])
        if current_value >= max_prev_value:
            sum += current_value
            max_prev_value = current_value
        else:
            sum -= current_value
    return sum

# Main method to handle user input and output
def main():
    roman_numeral = input("Enter a Roman numeral: ")
    try:
        result = roman_to_int(roman_numeral)
        print(f"Integer value: {result}")
    except ValueError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()

This code provides a comprehensive solution for converting Roman numerals to integers. It includes detailed comments to explain each logical block, making it easier to understand and maintain.

Translate the above Python code to JavaScript and end with comment "