import sys
import math
from decimal import Decimal, ROUND_HALF_UP

def main():
    try:
        input_value = float(sys.stdin.readline().strip())

        # Calculate the number of odd numbers in the input
        count_odd = math.floor(input_value / 2)

        # Create a Decimal object for the result
        result = Decimal(count_odd / input_value).quantize(Decimal('1E-10'), ROUND_HALF_UP)

        # Print the result
        print(result)
    except ValueError:
        print("Invalid input. Please enter a valid number.", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"An error occurred: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
