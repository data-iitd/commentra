class BaseConverter:
    @staticmethod
    def convert_base(source_number, source_base, dest_base):
        # Validate that the source and destination bases are within the acceptable range
        if source_base < 2 or source_base > 10 or dest_base < 2 or dest_base > 10:
            raise ValueError("Bases must be between 2 and 10.")
        
        # Convert the source number to decimal
        decimal_value = BaseConverter.to_decimal(source_number, source_base)
        # Convert the decimal value to the destination base
        return BaseConverter.from_decimal(decimal_value, dest_base)

    @staticmethod
    def to_decimal(number, base):
        decimal_value = 0  # Variable to hold the decimal value
        multiplier = 1     # Multiplier for the current base power
        # Loop until the number is reduced to zero
        while number != 0:
            # Add the current digit's contribution to the decimal value
            decimal_value += (number % 10) * multiplier
            # Update the multiplier for the next digit
            multiplier *= base
            # Remove the last digit from the number
            number //= 10
        return decimal_value  # Return the converted decimal value

    @staticmethod
    def from_decimal(decimal, base):
        result = 0  # Variable to hold the result in the new base
        multiplier = 1  # Multiplier for the current base power
        # Loop until the decimal value is reduced to zero
        while decimal != 0:
            # Add the current digit's contribution to the result
            result += (decimal % base) * multiplier
            # Update the multiplier for the next digit
            multiplier *= 10
            # Remove the last digit from the decimal value
            decimal //= base
        return result  # Return the converted value in the new base

if __name__ == "__main__":
    # Read the source number, source base, and destination base from input
    source_number = int(input())
    source_base = int(input())
    dest_base = int(input())
    try:
        # Convert the number and print the result
        result = BaseConverter.convert_base(source_number, source_base, dest_base)
        print("Converted number:", result)
    except ValueError as e:
        # Handle invalid base input by printing an error message
        print("Error:", e)

# <END-OF-CODE>
