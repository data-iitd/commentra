import sys
from decimal import Decimal, ROUND_HALF_UP

# Import statements to handle input/output operations and mathematical calculations

def main():
    # Main method is the entry point of the program
    
    try:
        input_value = float(sys.stdin.readline().strip())
        
        # Reading a float value from the input
        
        count_odd = round(input_value / 2)
        
        # Calculating the number of odd numbers up to the given input
        
        result = Decimal(count_odd / input_value).quantize(Decimal('1E10'), ROUND_HALF_UP)
        
        # Using Decimal to handle precise decimal calculations and setting the scale to 10
        
        print(result)
        
        # Printing the result
        
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        sys.exit(1)
        
    except Exception as e:
        print(e)
        sys.exit(1)

# Call the main method
if __name__ == "__main__":
    main()

