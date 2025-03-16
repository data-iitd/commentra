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
    
    if remainder <= 20:
        result = base_numbers_map[remainder]
    elif remainder in base_numbers_map:
        result = base_numbers_map[remainder]
    else:
        tens_digit = remainder // 10
        ones_digit = remainder % 10
        tens = base_numbers_map.get(tens_digit * 10, "")
        ones = base_numbers_map.get(ones_digit, "")
        result = tens + (" " + ones if ones else "")
    
    hundreds_digit = number // 100
    if hundreds_digit > 0:
        result = (f"{base_numbers_map[hundreds_digit]} Hundred" + (" " + result if result else ""))
    
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
            if sub_result:
                if index > 0:
                    sub_result += " " + thousand_power_map[index]
                if result:
                    result = " " + result
                result = sub_result + result
            index += 1
    
    return result.strip()

# Example usage:
# print(integer_to_english_words(123456789))
