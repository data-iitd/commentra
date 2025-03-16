
# A map to convert numbers to their English word representation for numbers 0-100 and multiples of ten
BASE_NUMBERS_MAP = {
    0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine",
    10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen", 17: "Seventeen",
    18: "Eighteen", 19: "Nineteen", 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty", 70: "Seventy",
    80: "Eighty", 90: "Ninety", 100: "Hundred"
}

# A map to represent the powers of thousand in English
THOUSAND_POWER_MAP = {
    1: "Thousand", 2: "Million", 3: "Billion"
}

# Private constructor to prevent instantiation of the Main class
class Main:
    def __init__(self):
        pass

def convert_to_words(number):
    # Calculate the remainder when divided by 100
    remainder = number % 100
    result = ""

    # Handle numbers from 0 to 20 directly
    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    elif BASE_NUMBERS_MAP.get(remainder):
        # Handle exact multiples of ten
        result = BASE_NUMBERS_MAP[remainder]
    else:
        # Handle numbers from 21 to 99
        tens_digit = remainder // 10
        ones_digit = remainder % 10
        tens = BASE_NUMBERS_MAP.get(tens_digit * 10, "")
        ones = BASE_NUMBERS_MAP.get(ones_digit, "")
        result = tens + " " + ones

    # Handle hundreds place
    hundreds_digit = number // 100
    if hundreds_digit > 0:
        if result:
            result = " " + result
        result = BASE_NUMBERS_MAP[hundreds_digit] + " Hundred" + result

    # Return the constructed word representation
    return result.strip()

def integer_to_english_words(number):
    # Validate that the number is non-negative
    if number < 0:
        raise ValueError("Number must be non-negative.")
    # Handle the special case for zero
    if number == 0:
        return "Zero"

    result = ""
    index = 0  # To track the power of thousand

    # Process the number in chunks of 1000
    while number > 0:
        remainder = number % 1000  # Get the last three digits
        number //= 1000  # Reduce the number

        # Convert the chunk to words if it's greater than zero
        if remainder > 0:
            sub_result = convert_to_words(remainder)
            if sub_result:
                # Append the appropriate thousand power if necessary
                if index > 0:
                    sub_result += " " + THOUSAND_POWER_MAP[index]
                if result:
                    result = " " + result
                result = sub_result + result

        index += 1  # Move to the next thousand power

    # Return the final constructed word representation
    return result.strip()

if __name__ == "__main__":
    # Create a scanner object to read input from the user
    scanner = Scanner(System.in)

    # Read an integer input from the user
    number = scanner.nextInt()

    # Close the scanner to prevent resource leaks
    scanner.close()

    try:
        # Convert the integer to its English word representation
        result = integer_to_english_words(number)
        # Output the result
        print("English Word Representation: " + result)
    except ValueError as e:
        # Handle invalid input by printing an error message
        print("Error: " + e.args[0])

