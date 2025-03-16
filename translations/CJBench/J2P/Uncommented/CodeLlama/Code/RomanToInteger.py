
import sys

def roman_to_int(roman_numeral):
    roman_numeral = roman_numeral.upper()
    roman_to_int_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    sum = 0
    max_prev_value = 0
    for i in range(len(roman_numeral) - 1, -1, -1):
        current_value = roman_to_int_map[roman_numeral[i]]
        if current_value >= max_prev_value:
            sum += current_value
            max_prev_value = current_value
        else:
            sum -= current_value
    return sum

def main():
    try:
        roman_numeral = sys.stdin.readline().strip()
        result = roman_to_int(roman_numeral)
        print("Integer value:", result)
    except KeyError as e:
        print("Error:", e)
    except ValueError as e:
        print("Error:", e)

if __name__ == "__main__":
    main()

