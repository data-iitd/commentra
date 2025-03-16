
# Map to store numbers from 0 to 20 and their corresponding words
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
# Map to store powers of thousand and their corresponding words
THOUSAND_POWER_MAP = {
    1: "Thousand",
    2: "Million",
    3: "Billion"
}
# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass
# Method to convert a number less than 100 into English words
def convert_to_words(number):
    remainder = number % 100
    result = ""
    # Handle numbers less than 20 directly
    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    # Handle numbers between 20 and 99
    elif BASE_NUMBERS_MAP.get(remainder):
        result = BASE_NUMBERS_MAP[remainder]
    else:
        tens_digit = remainder // 10
        ones_digit = remainder % 10
        tens = BASE_NUMBERS_MAP.get(tens_digit * 10, "")
        ones = BASE_NUMBERS_MAP.get(ones_digit, "")
        result = tens + " " + ones
    # Handle hundreds
    hundreds_digit = number // 100
    if hundreds_digit > 0:
        if result:
            result = " " + BASE_NUMBERS_MAP[hundreds_digit] + " Hundred"
        else:
            result = BASE_NUMBERS_MAP[hundreds_digit] + " Hundred"
    return result.strip()
# Method to convert an integer into English words
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
                    result = " " + sub_result
                else:
                    result = sub_result
        index += 1
    return result.strip()
# Main method to run the program
def main():
    # Initialize scanner to read input
    scanner = input("Enter a number: ")
    # Read the integer input
    number = int(scanner)
    # Try to convert the number to English words and print the result or error message
    try:
        result = integer_to_english_words(number)
        print("English Word Representation: " + result)
    except ValueError as e:
        print("Error: " + str(e))
# Call the main method
main()
# END-OF-CODE
