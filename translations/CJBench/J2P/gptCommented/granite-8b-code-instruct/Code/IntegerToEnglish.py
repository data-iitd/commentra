
import math

# A map to convert numbers to their English word representation for numbers 0-100 and multiples of ten
BASE_NUMBERS_MAP = {
    0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine",
    10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen",
    17: "Seventeen", 18: "Eighteen", 19: "Nineteen", 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty",
    60: "Sixty", 70: "Seventy", 80: "Eighty", 90: "Ninety"
}

# A map to represent the powers of thousand in English
THOUSAND_POWER_MAP = {
    1: "Thousand", 2: "Million", 3: "Billion"
}

# Convert a number less than 1000 to its English word representation
def convertToWords(number):
    # Calculate the remainder when divided by 100
    remainder = number % 100
    result = ""
    
    # Handle numbers from 0 to 20 directly
    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    elif remainder in BASE_NUMBERS_MAP:
        # Handle exact multiples of ten
        result = BASE_NUMBERS_MAP[remainder]
    else:
        # Handle numbers from 21 to 99
        tensDigit = remainder // 10
        onesDigit = remainder % 10
        tens = BASE_NUMBERS_MAP.get(tensDigit * 10, "")
        ones = BASE_NUMBERS_MAP.get(onesDigit, "")
        result = tens
        if ones:
            result += " " + ones
    
    # Handle hundreds place
    hundredsDigit = number // 100
    if hundredsDigit > 0:
        if result:
            result = " " + result
        result = f"{BASE_NUMBERS_MAP[hundredsDigit]} Hundred{result}"
    
    # Return the constructed word representation
    return result.strip()

# Convert an integer to its English word representation
def integerToEnglishWords(number):
    # Validate that the number is non-negative
    if number < 0:
        raise ValueError("Number must be non-negative.")
    # Handle the special case for zero
    if number == 0:
        return "Zero"
    
    result = ""
    index = 0 # To track the power of thousand
    
    # Process the number in chunks of 1000
    while number > 0:
        remainder = number % 1000 # Get the last three digits
        number //= 1000 # Reduce the number
        
        # Convert the chunk to words if it's greater than zero
        if remainder > 0:
            subResult = convertToWords(remainder)
            if subResult:
                # Append the appropriate thousand power if necessary
                if index > 0:
                    subResult += " " + THOUSAND_POWER_MAP[index]
                if result:
                    result = " " + result
                result = subResult + result
        index += 1 # Move to the next thousand power
    
    # Return the final constructed word representation
    return result.strip()

# Test the function
print(integerToEnglishWords(1234567890)) # Output: "One Billion Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

# END-OF-CODE