import sys

def main():
    number = int(sys.stdin.readline())
    base = lowest_base_palindrome(number)
    print(base)

def compute_digits_in_base(number, base):
    digits = []
    while number > 0:
        digits.append(number % base)
        number //= base
    return digits

def is_palindromic(list):
    size = len(list)
    for i in range(size // 2):
        if list[i]!= list[size - 1 - i]:
            return False
    return True

def is_palindromic_in_base(number, base):
    if number <= 1:
        return True
    if number % base == 0:
        return False
    return is_palindromic(compute_digits_in_base(number, base))

def lowest_base_palindrome(number):
    base = 2
    while not is_palindromic_in_base(number, base):
        base += 1
    return base

if __name__ == '__main__':
    main()

