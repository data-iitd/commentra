def roman_to_int(roman):
    roman_to_int_map = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    if roman is None:
        raise ValueError("Input cannot be null")

    roman = roman.upper()
    total = 0
    max_prev_value = 0

    for char in reversed(roman):
        value = roman_to_int_map[char]
        if value >= max_prev_value:
            total += value
            max_prev_value = value
        else:
            total -= value

    return total


def main():
    import sys
    input_roman = sys.stdin.readline().strip()

    try:
        result = roman_to_int(input_roman)
        print(f"Integer value: {result}")
    except (ValueError, KeyError) as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
