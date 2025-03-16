import sys  # Importing the sys module for reading input

def main():  # Defining the main function
    while True:  # Starting an infinite loop
        try:
            # Reading input from standard input and unpacking into variables a to f
            a, b, c, d, e, f = map(int, input().split())
            
            # Calculating the value of y using the given formula
            y = (c * d - f * a) / (b * d - e * a)
            # Calculating the value of x using the given formula
            x = (c * e - f * b) / (a * e - d * b)
            
            # Checking if y is less than or equal to a very small positive number
            if y <= 0.0005:
                y = 0  # If so, set y to 0
            # Checking if x is less than or equal to a very small positive number
            if x <= 0.0005:
                x = 0  # If so, set x to 0
            
            # Printing the values of x and y to the standard output with three decimal places
            print(f"{x:.3f} {y:.3f}")
        
        except EOFError:  # Catching end of file error
            break  # Exiting the loop
        except ValueError:  # Catching value error in case of invalid input
            break  # Exiting the loop

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>
