import sys
import math
from decimal import Decimal, ROUND_HALF_UP

def main():
    try:
        # Read a line of input from the console
        input_line = sys.stdin.readline().strip()
        
        # Parse the input as a float
        input_value = float(input_line)
        
        # Calculate the count of odd numbers based on the input
        count_odd = math.floor(input_value / 2)
        
        # Create a Decimal to hold the result of the division
        result = Decimal(count_odd) / Decimal(input_value)
        
        # Set the scale of the result to 10 decimal places, rounding half up
        result = result.quantize(Decimal('1E-10'), ROUND_HALF_UP)
        
        # Print the result to the console
        print(result)
    except ValueError:
        # Handle value errors (e.g., invalid input format)
        print("Invalid input. Please enter a valid number.")
        sys.exit(1)
    except Exception as e:
        # Handle any other exceptions that may occur
        print(e)
        sys.exit(1)

if __name__ == "__main__":
    main()
