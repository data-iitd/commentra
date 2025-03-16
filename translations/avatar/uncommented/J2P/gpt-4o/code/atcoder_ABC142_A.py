import sys
from decimal import Decimal, ROUND_HALF_UP

def main():
    try:
        input_value = float(input())
        count_odd = round(input_value / 2)
        result = Decimal(count_odd) / Decimal(input_value)
        result = result.quantize(Decimal('1.0000000000'), rounding=ROUND_HALF_UP)
        print(result)
    except (IOError, ValueError) as e:
        print(e)
        sys.exit(0)
    except Exception as e:
        print(e)
        sys.exit(0)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
