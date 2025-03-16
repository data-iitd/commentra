

import math
import decimal

# Import statements to handle mathematical calculations and decimal precision

def main():
    try:
        input = float(input())
        
        # Reading a float value from the input
        
        countOdd = math.floor(input / 2)
        
        # Calculating the number of odd numbers up to the given input
        
        result = decimal.Decimal(countOdd / input)
        result = result.quantize(decimal.Decimal('1.000000000'))
        
        # Using decimal to handle precise decimal calculations and setting the scale to 10
        
        print(result)
        
        # Printing the result
        
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        
    except Exception as e:
        print("An error occurred:", e)

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "