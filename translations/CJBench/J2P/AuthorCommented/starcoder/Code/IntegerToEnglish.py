
import re

BASE_NUMBERS_MAP = {
    0: "",
    1: "One",
    2: "Two",
    3: "Three",
    4: "Four",
    5: "Five",
    6: "Six",
    7: "Seven",
    8: "Eight",
    9: "Nine",
    10: "Ten",
    11: "Eleven",
    12: "Twelve",
    13: "Thirteen",
    14: "Fourteen",
    15: "Fifteen",
    16: "Sixteen",
    17: "Seventeen",
    18: "Eighteen",
    19: "Nineteen",
    20: "Twenty",
    30: "Thirty",
    40: "Forty",
    50: "Fifty",
    60: "Sixty",
    70: "Seventy",
    80: "Eighty",
    90: "Ninety",
    100: "Hundred"
}

THOUSAND_POWER_MAP = {
    1: "Thousand",
    2: "Million",
    3: "Billion"
}

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
            sub_result = convert_to_words(remainder)
            if sub_result:
                if index > 0:
                    sub_result += " " + THOUSAND_POWER_MAP[index]
                if result:
                    result = " " + sub_result + result
                else:
                    result = sub_result

        index += 1

    return result.strip()

def convert_to_words(number):
    remainder = number % 100
    result = ""

    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    elif BASE_NUMBERS_MAP.get(remainder):
        result = BASE_NUMBERS_MAP[remainder]
    else:
        tens_digit = remainder // 10
        ones_digit = remainder % 10
        tens = BASE_NUMBERS_MAP.get(tens_digit * 10)
        ones = BASE_NUMBERS_MAP.get(ones_digit)
        result = tens
        if ones:
            result += " " + ones

    hundreds_digit = number // 100
    if hundreds_digit > 0:
        if result:
            result = " " + result
        result = BASE_NUMBERS_MAP[hundreds_digit] + " Hundred" + result

    return result.strip()

if __name__ == "__main__":
    import sys

    try:
        number = int(sys.argv[1])
        result = integer_to_english_words(number)
        print("English Word Representation: " + result)
    except (IndexError, ValueError) as e:
        print("Error: " + str(e))

