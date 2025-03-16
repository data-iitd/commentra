def check_base(base):
    if base <= 1:
        raise ValueError("Base must be greater than 1.")

def check_number(number):
    if number < 0:
        raise ValueError("Number must be non-negative.")

def compute_digits_in_base(number, base):
    check_number(number)
    check_base(base)
    digits = []
    while number > 0:
        digits.append(number % base)
        number //= base
    return digits

def is_palindromic(digits):
    size = len(digits)
    for i in range(size // 2):
        if digits[i] != digits[size - 1 - i]:
            return False
    return True

def is_palindromic_in_base(number, base):
    check_number(number)
    check_base(base)
    if number <= 1:
        return True
    if number % base == 0:
        return False
    return is_palindromic(compute_digits_in_base(number, base))

def lowest_base_palindrome(number):
    check_number(number)
    base = 2
    while not is_palindromic_in_base(number, base):
        base += 1
    return base

# Main program
if __name__ == "__main__":
    import sys
    number = int(sys.stdin.readline().strip())
    base = lowest_base_palindrome(number)
    print(base)
