import sys

# Import statements to handle input/output operations

def main():
    # Main function is the entry point of the program
    try:
        input_value = float(input())
        
        # Reading a float value from the input
        
        count_odd = round(input_value / 2)
        
        # Calculating the number of odd numbers up to the given input
        
        result = count_odd / input_value
        
        # Using float to handle decimal calculations
        
        print(f"{result:.10f}")
        
        # Printing the result with a precision of 10 decimal places
        
    except (IOError, ValueError) as e:
        print(e)
        sys.exit(0)
        
        # Handling IOError and ValueError to ensure program termination
        
    except Exception as e:
        print(e)
        sys.exit(0)
        
        # Handling any other potential exceptions to ensure program termination

if __name__ == "__main__":
    main()

# <END-OF-CODE>
