import sys
from decimal import Decimal, ROUND_HALF_UP

def main():
    try:
        # Read a line of input and parse it as a float
        input_value = float(input())
        
        # Calculate the count of odd numbers based on the input
        count_odd = round(input_value / 2)
        
        # Create a Decimal to hold the result of the division
        result = Decimal(count_odd) / Decimal(input_value)
        
        # Set the scale of the result to 10 decimal places, rounding half up
        result = result.quantize(Decimal('0.0000000000'), rounding=ROUND_HALF_UP)
        
        # Print the result to the console
        print(result)
    except (IOError, ValueError) as e:
        # Handle input/output exceptions and number format exceptions
        print(e)
        sys.exit(0)
    except Exception as e:
        # Handle any other exceptions that may occur
        print(e)
        sys.exit(0)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
