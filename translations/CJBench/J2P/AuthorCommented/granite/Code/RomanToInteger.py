

import re

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
    return ROMAN_TO_INT.get(symbol, None)

def roman_to_int(roman):
    roman = roman.upper()
    sum = 0
    max_prev_value = 0
    for i in range(len(roman) - 1, -1, -1):
        current_value = roman_symbol_to_int(roman[i])
        if current_value is None:
            raise ValueError("Unknown Roman symbol: " + roman[i])
        if current_value >= max_prev_value:
            sum += current_value
            max_prev_value = current_value
        else:
            sum -= current_value
    return sum

if __name__ == "__main__":
    roman_numeral = input("Enter a Roman numeral: ")
    try:
        result = roman_to_int(roman_numeral)
        print("Integer value:", result)
    except ValueError as e:
        print("Error:", e)

