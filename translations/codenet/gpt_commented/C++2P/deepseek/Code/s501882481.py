# Python code translated from the provided C++ code

# Import necessary modules
import sys

# Function to convert a string to string (identity function)
def to_string(s):
    return s

# Template function to convert a pair to string representation
def to_string(p):
    return "{" + to_string(p[0]) + "," + to_string(p[1]) + "}"

# Template function to convert a vector to string representation
def to_string(v):
    ret = "{"
    for i in range(len(v) - 1):
        ret += to_string(v[i]) + ","
    if len(v) > 0:
        ret += to_string(v[-1])
    ret += "}"
    return ret

# Function to print a new line for debugging purposes
def debug(*args):
    print(" ".join(map(str, args)), file=sys.stderr)

# Template function to print multiple values for debugging
def print(*args):
    print(" ".join(map(str, args)))

# Function to handle no input (base case for variadic template)
def get():
    pass

# Template function to read multiple values from standard input
def get(*args):
    inputs = list(map(str.strip, sys.stdin.readline().split()))
    for i, arg in enumerate(args):
        arg.append(inputs[i])

# Template function to read values into a vector from standard input
def getv(vec):
    inputs = list(map(str.strip, sys.stdin.readline().split()))
    for i in range(len(vec)):
        vec[i] = inputs[i]

# Main function where the program execution begins
def main():
    S = input().strip()  # Read the weather condition from standard input

    # Determine the next weather condition based on the current one
    if S == "Sunny":
        print("Cloudy")  # If it's sunny, print "Cloudy"
    elif S == "Cloudy":
        print("Rainy")  # If it's cloudy, print "Rainy"
    else:
        print("Sunny")  # If it's neither, it must be rainy, print "Sunny"

# Call the main function
if __name__ == "__main__":
    main()
