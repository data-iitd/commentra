# Import necessary modules
import sys

# Define a function to convert a string to a string representation
def to_string(s):
    return s

# Define a function to convert a pair to a string representation
def to_string(p):
    return "{" + to_string(p[0]) + "," + to_string(p[1]) + "}"

# Define a function to convert a vector to a string representation
def to_string(v):
    return "{" + ",".join(map(to_string, v)) + "}"

# Define a debug function to print debug information
def debug(*args):
    print(" ".join(map(str, args)))

# Define a print function to print multiple items
def print(*args):
    print(" ".join(map(str, args)))

# Utility function to read a single item
def get():
    return input().strip()

# Utility function to read multiple items
def getv(n):
    return [input().strip() for _ in range(n)]

# Main function to execute the program
def main():
    S = get()
    if S == "Sunny":
        print("Cloudy")
    elif S == "Cloudy":
        print("Rainy")
    else:
        print("Sunny")

# Execute the main function
if __name__ == "__main__":
    main()
