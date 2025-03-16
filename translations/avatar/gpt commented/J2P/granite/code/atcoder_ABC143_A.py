
import sys

def main():
    try:
        # Read a line of input, split it into an array of strings, and parse the first and second elements as integers
        x = input().split()
        a = int(x[0])
        b = int(x[1])
        
        # Calculate the value of c based on the formula: c = a - b * 2
        c = a - b * 2
        
        # If c is negative, set it to 0
        if c < 0:
            c = 0
        
        # Output the final value of c
        print(c)
    except Exception as e:
        # Handle any exceptions that may occur during input or processing
        print(e)

if __name__ == "__main__":
    main()

