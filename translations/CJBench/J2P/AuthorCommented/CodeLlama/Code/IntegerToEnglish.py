
import sys

# A utility class to convert integers to their English word representation.
#
# The class supports conversion of numbers from 0 to 2,147,483,647
# (the maximum value of a 32-bit signed integer). It divides the number
# into groups of three digits (thousands, millions, billions, etc.) and
# translates each group into words.
#
# <h2>Example Usage</h2>
# <pre>
#   Main.integerToEnglishWords(12345);
#   # Output: "Twelve Thousand Three Hundred Forty Five"
# </pre>
#
# This class uses two maps:
# <ul>
#   <li>BASE_NUMBERS_MAP: Holds English words for numbers 0-20, multiples of 10 up to 90, and 100.</li>
#   <li>THOUSAND_POWER_MAP: Maps powers of 1000 (e.g., Thousand, Million, Billion).</li>
# </ul>
class Main:

    # Converts numbers less than 1000 into English words.
    #
    # @param number the integer value (0-999) to convert
    # @return the English word representation of the input number
    @staticmethod
    def convert_to_words(number):
        remainder = number % 100
        result = ""

        if remainder <= 20:
            result = Main.BASE_NUMBERS_MAP.get(remainder)
        elif Main.BASE_NUMBERS_MAP.get(remainder):
            result = Main.BASE_NUMBERS_MAP.get(remainder)
        else:
            tens_digit = remainder // 10
            ones_digit = remainder % 10
            tens = Main.BASE_NUMBERS_MAP.get(tens_digit * 10, "")
            ones = Main.BASE_NUMBERS_MAP.get(ones_digit, "")
            result = tens + " " + ones

        hundreds_digit = number // 100
        if hundreds_digit > 0:
            if result:
                result = " " + Main.BASE_NUMBERS_MAP.get(hundreds_digit) + " Hundred"
            else:
                result = Main.BASE_NUMBERS_MAP.get(hundreds_digit) + " Hundred"

        return result.strip()

    # Converts a non-negative integer to its English word representation.
    #
    # @param number the integer to convert (0-2,147,483,647)
    # @return the English word representation of the input number
    @staticmethod
    def integer_to_english_words(number):
        if number < 0:
            raise ValueError("Number must be non-negative.")
        if number == 0:
            return "Zero"

        result = ""
        index = 0

        while number > 0:
            remainder = number % 1000
            number //= 1000

            if remainder > 0:
                sub_result = Main.convert_to_words(remainder)
                if sub_result:
                    if index > 0:
                        sub_result += " " + Main.THOUSAND_POWER_MAP.get(index)
                    if result:
                        result = " " + sub_result
                    else:
                        result = sub_result

            index += 1

        return result.strip()


# 