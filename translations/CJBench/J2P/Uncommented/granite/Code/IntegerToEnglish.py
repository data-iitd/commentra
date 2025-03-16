

BASE_NUMBERS_MAP = {
    0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine",
    10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen",
    17: "Seventeen", 18: "Eighteen", 19: "Nineteen", 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty",
    60: "Sixty", 70: "Seventy", 80: "Eighty", 90: "Ninety", 100: "Hundred"
}
THOUSAND_POWER_MAP = {
    1: "Thousand", 2: "Million", 3: "Billion"
}
def convertToWords(number):
    remainder = number % 100
    result = ""
    if remainder <= 20:
        result = BASE_NUMBERS_MAP[remainder]
    elif remainder in BASE_NUMBERS_MAP:
        result = BASE_NUMBERS_MAP[remainder]
    else:
        tensDigit = remainder // 10
        onesDigit = remainder % 10
        tens = BASE_NUMBERS_MAP.get(tensDigit * 10, "")
        ones = BASE_NUMBERS_MAP.get(onesDigit, "")
        result = tens
        if ones:
            result += " " + ones
    hundredsDigit = number // 100
    if hundredsDigit > 0:
        if result:
            result = " " + result
        result = BASE_NUMBERS_MAP[hundredsDigit] + " Hundred" + result
    return result.strip()
def integerToEnglishWords(number):
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
            subResult = convertToWords(remainder)
            if subResult:
                if index > 0:
                    subResult += " " + THOUSAND_POWER_MAP[index]
                if result:
                    result = " " + result
                result = subResult + result
        index += 1
    return result.strip()
# 