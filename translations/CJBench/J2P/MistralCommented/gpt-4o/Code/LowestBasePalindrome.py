class Main:
    @staticmethod
    def check_base(base):
        if base <= 1:
            raise ValueError("Base must be greater than 1.")

    @staticmethod
    def check_number(number):
        if number < 0:
            raise ValueError("Number must be non-negative.")

    @staticmethod
    def compute_digits_in_base(number, base):
        Main.check_number(number)
        Main.check_base(base)

        digits = []

        while number > 0:
            digits.append(number % base)
            number //= base

        return digits

    @staticmethod
    def is_palindromic(lst):
        size = len(lst)

        if size % 2 != 0:
            return False

        for i in range(size // 2):
            if lst[i] != lst[size - 1 - i]:
                return False

        return True

    @staticmethod
    def is_palindromic_in_base(number, base):
        Main.check_number(number)
        Main.check_base(base)

        if number <= 1:
            return True

        if number % base == 0:
            return False

        digits = Main.compute_digits_in_base(number, base)
        return Main.is_palindromic(digits)

    @staticmethod
    def lowest_base_palindrome(number):
        Main.check_number(number)

        base = 2
        while not Main.is_palindromic_in_base(number, base):
            base += 1

        return base

if __name__ == "__main__":
    number = int(input())
    Main.check_number(number)
    base = Main.lowest_base_palindrome(number)
    print(base)

# <END-OF-CODE>
