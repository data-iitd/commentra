import math

def main():
    try:
        # Create a BufferedReader to read input from the console
        br = open("input.txt", "r")

        # Read a line of input and parse it as a double
        input = float(br.readline())

        # Calculate the count of odd numbers based on the input
        countOdd = math.floor(input / 2)

        # Create a BigDecimal to hold the result of the division
        result = countOdd / input

        # Set the scale of the result to 10 decimal places, rounding half up
        result = round(result, 10)

        # Print the result to the console
        print(result)
    except (IOError, ValueError) as e:
        # Handle input/output exceptions and number format exceptions
        print(e)
        exit(0)
    except Exception as e:
        # Handle any other exceptions that may occur
        print(e)
        exit(0)

if __name__ == "__main__":
    main()

