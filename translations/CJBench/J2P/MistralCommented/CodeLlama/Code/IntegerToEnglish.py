
import sys

# Initialize a dictionary to store base numbers and their English words representation
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

# Initialize a dictionary to store thousand power and their English words representation
THOUSAND_POWER_MAP = {
    1: "Thousand",
    2: "Million",
    3: "Billion"
}

# Convert an integer number to its English words representation
def convert_to_words(number):
    remainder = number % 100
    result = ""

    # Handle the case when the remainder is less than or equal to 20
    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    elif BASE_NUMBERS_MAP.get(remainder):
        # Handle the case when the remainder is a two-digit number
        result = BASE_NUMBERS_MAP[remainder // 10 * 10]

        # Handle the case when the remainder is a number between 21 and 99
        ones_digit = remainder % 10
        if ones_digit > 0:
            ones = BASE_NUMBERS_MAP.get(ones_digit, "")
            result += " " + ones

    # Handle the case when the number has hundreds digit
    hundreds_digit = number // 100
    if hundreds_digit > 0:
        hundreds = BASE_NUMBERS_MAP[hundreds_digit]
        if result:
            result = " " + hundreds + " Hundred"
        else:
            result = hundreds + " Hundred"

    return result.strip()

# Convert an integer number to its English words representation
def integer_to_english_words(number):
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
            sub_result = convert_to_words(remainder)
            if sub_result:
                if index > 0:
                    sub_result += " " + THOUSAND_POWER_MAP[index]
                if result:
                    result = " " + sub_result
                else:
                    result = sub_result

        index += 1

    return result.strip()

# Read an integer number from the console
number = int(input("Enter a number: "))

# Convert the integer number to its English words representation
result = integer_to_english_words(number)

# Print the English words representation to the console
print("English Word Representation:", result)

