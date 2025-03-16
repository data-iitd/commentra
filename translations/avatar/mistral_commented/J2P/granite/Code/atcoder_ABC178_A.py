
# Importing necessary Python libraries for this program
import sys  # For reading user input from the standard input

# Main function is the entry point of the Python application
def main():
    # Reading an integer value from the user input
    x = int(sys.stdin.readline())

    # Determining a boolean value based on the condition x equals to 1
    bool = True if x == 1 else False

    # Calculating the result based on the boolean value
    result = 1 if not bool else 0

    # Writing the result to the standard output
    sys.stdout.write(str(result) + '\n')

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

