
import sys

# Function to print a new line for debugging purposes
def debug():
    print()

# Template function to print multiple values for debugging
def debug(*args):
    print(*args)

# Function to print a new line
def print():
    print()

# Template function to print multiple values to standard output
def print(*args):
    print(*args)

# Function to handle no input (base case for variadic template)
def get():
    pass

# Template function to read multiple values from standard input
def get(*args):
    for arg in args:
        arg = input()

# Template function to read values into a vector from standard input
def getv(vec):
    for i in range(len(vec)):
        vec[i] = int(input())

# Main function where the program execution begins
def main():
    S = input() # Read the weather condition from standard input

    # Determine the next weather condition based on the current one
    if S == "Sunny":
        print("Cloudy") # If it's sunny, print "Cloudy"
    elif S == "Cloudy":
        print("Rainy") # If it's cloudy, print "Rainy"
    else:
        print("Sunny") # If it's neither, it must be rainy, print "Sunny"

    return 0 # Return 0 to indicate successful execution

if __name__ == "__main__":
    sys.exit(main())

