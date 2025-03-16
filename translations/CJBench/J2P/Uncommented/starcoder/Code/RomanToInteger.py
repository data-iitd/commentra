
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

def romanSymbolToInt(symbol):
    return ROMAN_TO_INT.get(symbol, None)

def romanToInt(roman):
    if roman is None:
        raise ValueError("Input cannot be null")
    roman = roman.upper()
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

if __name__ == '__main__':
    try:
        romanNumeral = input()
        result = romanToInt(romanNumeral)
        print("Integer value: " + str(result))
    except ValueError as e:
        print("Error: " + e.args[0])

