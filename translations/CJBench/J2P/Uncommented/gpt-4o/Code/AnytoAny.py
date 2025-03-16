class BaseConverter:
    @staticmethod
    def convert_base(source_number, source_base, dest_base):
        if source_base < 2 or source_base > 10 or dest_base < 2 or dest_base > 10:
            raise ValueError("Bases must be between 2 and 10.")
        decimal_value = BaseConverter.to_decimal(source_number, source_base)
        return BaseConverter.from_decimal(decimal_value, dest_base)

    @staticmethod
    def to_decimal(number, base):
        decimal_value = 0
        multiplier = 1
        while number != 0:
            decimal_value += (number % 10) * multiplier
            multiplier *= base
            number //= 10
        return decimal_value

    @staticmethod
    def from_decimal(decimal, base):
        result = 0
        multiplier = 1
        while decimal != 0:
            result += (decimal % base) * multiplier
            multiplier *= 10
            decimal //= base
        return result

if __name__ == "__main__":
    source_number = int(input())
    source_base = int(input())
    dest_base = int(input())
    try:
        result = BaseConverter.convert_base(source_number, source_base, dest_base)
        print("Converted number:", result)
    except ValueError as e:
        print("Error:", e)

# <END-OF-CODE>
