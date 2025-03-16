

def integer_to_english_words(number):
    if number < 0:
        raise ValueError("Number must be non-negative.")

    if number == 0:
        return "Zero"

    base_numbers_map = {
        0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine",
        10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen",
        17: "Seventeen", 18: "Eighteen", 19: "Nineteen", 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty",
        60: "Sixty", 70: "Seventy", 80: "Eighty", 90: "Ninety"
    }

    thousand_power_map = {
        1: "Thousand", 2: "Million", 3: "Billion"
    }

    result = []
    index = 0

    while number > 0:
        remainder = number % 1000
        number //= 1000

        if remainder > 0:
            sub_result = ""
            if remainder >= 100:
                sub_result += base_numbers_map[remainder // 100] + " Hundred"
                remainder %= 100
            if remainder >= 20:
                sub_result += base_numbers_map[remainder // 10 * 10]
                remainder %= 10
            if remainder > 0:
                sub_result += " " + base_numbers_map[remainder]
            if sub_result:
                if index > 0:
                    sub_result += " " + thousand_power_map[index]
                result.insert(0, sub_result)
        index += 1

    return " ".join(result).strip()

