
import re

# Initialize a map to store base numbers and their English words representation
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

# Initialize a map to store thousand power and their English words representation
THOUSAND_POWER_MAP = {
    1: "Thousand",
    2: "Million",
    3: "Billion"
}

# Convert an integer number to its English words representation
def convertToWords(number):
    remainder = number % 100
    result = ""

    # Handle the case when the remainder is less than or equal to 20
    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    elif BASE_NUMBERS_MAP.get(remainder):
        # Handle the case when the remainder is a two-digit number
        result = BASE_NUMBERS_MAP[remainder // 10 * 10]

        # Handle the case when the remainder is a number between 21 and 99
        onesDigit = remainder % 10
        if onesDigit > 0:
            ones = BASE_NUMBERS_MAP.get(onesDigit, "")
            result += " " + ones
    return result.strip()

# Convert an integer number to its English words representation
def integerToEnglishWords(number):
    if number < 0:
        raise ValueError("Number must be non-negative.")

    if number == 0:
        return "Zero"

    result = ""
    index = 0

    # Convert the number to its English words representation by iterating through its digits
    while number > 0:
        remainder = number % 1000
        number //= 1000

        # If the remainder is greater than zero, convert it to English words and add it to the result
        if remainder > 0:
            subResult = convertToWords(remainder)
            if subResult:
                if index > 0:
                    subResult += " " + THOUSAND_POWER_MAP[index]
                if result:
                    result = " " + subResult + result
                else:
                    result = subResult
        index += 1
    return result.strip()

# Read an integer number from the console
number = int(input())

# Convert the integer number to its English words representation
result = integerToEnglishWords(number)

# Print the English words representation to the console
print("English Word Representation: " + result)

# 