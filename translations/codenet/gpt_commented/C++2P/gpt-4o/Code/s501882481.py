# Import necessary modules
import sys

# Function to print multiple values to standard output
def print_values(*args):
    print(*args)

# Main function where the program execution begins
def main():
    S = input().strip()  # Read the weather condition from standard input

    # Determine the next weather condition based on the current one
    if S == "Sunny":
        print_values("Cloudy")  # If it's sunny, print "Cloudy"
    elif S == "Cloudy":
        print_values("Rainy")  # If it's cloudy, print "Rainy"
    else:
        print_values("Sunny")  # If it's neither, it must be rainy, print "Sunny"

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
