def damm_check(digits):
    if not digits.isdigit():
        raise ValueError(f"Input '{digits}' contains not only digits")
    
    numbers = [int(digit) for digit in digits]
    checksum = 0
    
    for number in numbers:
        checksum = damm_table[checksum][number]
    
    return checksum == 0


def add_main_checksum(initial_digits):
    if not initial_digits.isdigit():
        raise ValueError(f"Input '{initial_digits}' contains not only digits")
    
    numbers = [int(digit) for digit in initial_digits]
    checksum = 0
    
    for number in numbers:
        checksum = damm_table[checksum][number]
    
    return initial_digits + str(checksum)


def main():
    operation = input().strip().lower()
    
    if operation == "check":
        digits = input().strip()
        try:
            is_valid = damm_check(digits)
            print(f"The input '{digits}' is {'valid' if is_valid else 'not valid'}")
        except Exception as e:
            print(f"Error: {e}")
    elif operation == "generate":
        print("Enter the input digits to generate checksum:")
        initial_digits = input().strip()
        try:
            result = add_main_checksum(initial_digits)
            print(f"Generated value with checksum: {result}")
        except Exception as e:
            print(f"Error: {e}")
    else:
        print("Invalid operation. Please enter 'check' or 'generate'.")


damm_table = [
    [0, 3, 1, 7, 5, 9, 8, 6, 4, 2],
    [7, 0, 9, 2, 1, 5, 4, 8, 6, 3],
    [4, 2, 0, 6, 8, 7, 1, 3, 5, 9],
    [1, 7, 5, 0, 9, 8, 3, 4, 2, 6],
    [6, 1, 2, 3, 0, 4, 5, 9, 7, 8],
    [3, 6, 7, 4, 2, 0, 9, 5, 8, 1],
    [5, 8, 6, 9, 7, 2, 0, 1, 3, 4],
    [8, 9, 4, 5, 3, 6, 2, 0, 1, 7],
    [9, 4, 3, 8, 6, 1, 7, 2, 0, 5],
    [2, 5, 8, 1, 4, 3, 6, 7, 9, 0],
]

if __name__ == "__main__":
    main()
