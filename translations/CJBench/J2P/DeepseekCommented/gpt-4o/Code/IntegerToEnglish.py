def convert_to_words(number):
    base_numbers_map = {
        0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four",
        5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine",
        10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen",
        14: "Fourteen", 15: "Fifteen", 16: "Sixteen", 17: "Seventeen",
        18: "Eighteen", 19: "Nineteen", 20: "Twenty", 30: "Thirty",
        40: "Forty", 50: "Fifty", 60: "Sixty", 70: "Seventy",
        80: "Eighty", 90: "Ninety", 100: "Hundred"
    }
    thousand_power_map = {
        1: "Thousand", 2: "Million", 3: "Billion"
    }
    
    remainder = number % 100
    result = ""
    
    # Handle numbers less than 20 directly
    if remainder <= 20:
        result = base_numbers_map[remainder]
    # Handle numbers between 20 and 99
    elif remainder in base_numbers_map:
        result = base_numbers_map[remainder]
    else:
        tens_digit = remainder // 10
        ones_digit = remainder % 10
        tens = base_numbers_map.get(tens_digit * 10, "")
        ones = base_numbers_map.get(ones_digit, "")
        result = tens
        if ones:
            result += " " + ones
    
    # Handle hundreds
    hundreds_digit = number // 100
    if hundreds_digit > 0:
        if result:
            result = " " + result
        result = f"{base_numbers_map[hundreds_digit]} Hundred{result}"
    
    return result.strip()

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
            if index > 0:
                sub_result += " " + thousand_power_map[index]
            if result:
                result = " " + result
            result = sub_result + result
        index += 1
    
    return result.strip()

# Main function to run the program
def main():
    number = int(input())
    try:
        result = integer_to_english_words(number)
        print("English Word Representation:", result)
    except ValueError as e:
        print("Error:", e)

if __name__ == "__main__":
    main()
