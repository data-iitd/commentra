import sys  # Import sys for handling standard input and output
from decimal import Decimal, ROUND_HALF_UP  # Import Decimal for decimal arithmetic and rounding

def main():
    try:  # Begin try block for handling normal input and calculation
        input_value = float(input())  # Read input from standard input and parse as float

        # Calculate the number of odd numbers in the input
        count_odd = round(input_value / 2)

        # Create a Decimal object for the result
        result = Decimal(count_odd) / Decimal(input_value)

        # Set the scale and rounding mode for the result
        result = result.quantize(Decimal('0.0000000000'), rounding=ROUND_HALF_UP)

        # Print the result
        print(result)
    except (IOError, ValueError) as e:  # Handle I/O errors and value errors
        print(e)  # Print the error message
        sys.exit(0)  # Exit the program with a zero status code
    except Exception as e:  # Handle other exceptions
        print(e)  # Print the error message
        sys.exit(0)  # Exit the program with a zero status code

if __name__ == "__main__":
    main()

# <END-OF-CODE>
