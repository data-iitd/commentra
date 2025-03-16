
import re

# A utility class to convert Roman numerals into integers.
#
# Roman numerals are based on seven symbols given below:
# I = 1
# V = 5
# X = 10
# L = 50
# C = 100
# D = 500
# M = 1000
#
# If a smaller numeral appears before a larger numeral, it is subtracted.
# Otherwise, it is added. For example:
# MCMXCIV = 1000 + (1000 - 100) + (100 - 10) + (5 - 1) = 1994
class Main:

    # A map of Roman symbols to their integer values.
    ROMAN_TO_INT = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    # Converts a single Roman numeral character to its integer value.
    @staticmethod
    def romanSymbolToInt(symbol):
        return Main.ROMAN_TO_INT.get(symbol, None)

    # Converts a Roman numeral string to its integer equivalent.
    # Steps:
    # 1. Iterate over the string from right to left.
    # 2. For each character, convert it to an integer value.
    # 3. If the current value is greater than or equal to the max previous value, add it.
    # 4. Otherwise, subtract it from the sum.
    # 5. Update the max previous value.
    # 6. Return the sum.
    @staticmethod
    def romanToInt(roman):
        if roman is None:
            raise ValueError("Input cannot be null")

        roman = roman.upper()
        sum = 0
        maxPrevValue = 0
        for i in range(len(roman) - 1, -1, -1):
            currentValue = Main.romanSymbolToInt(roman[i])
            if currentValue >= maxPrevValue:
                sum += currentValue
                maxPrevValue = currentValue
            else:
                sum -= currentValue

        return sum

# 