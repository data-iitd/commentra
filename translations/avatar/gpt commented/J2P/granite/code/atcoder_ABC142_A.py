
import math

def main():
    try:
        # Read a line of input and parse it as a float
        input = float(input())
        
        # Calculate the count of odd numbers based on the input
        countOdd = math.floor(input / 2)
        
        # Calculate the result of the division
        result = countOdd / input
        
        # Print the result to the console
        print(round(result, 10))
    except ValueError:
        # Handle input parsing exceptions
        print("Invalid input")
    except Exception as e:
        # Handle any other exceptions that may occur
        print("An error occurred:", e)

if __name__ == "__main__":
    main()

