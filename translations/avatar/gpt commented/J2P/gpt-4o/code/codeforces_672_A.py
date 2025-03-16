# Importing the sys module for user input
import sys

# Function to generate a character array from the concatenation of numbers 1 to 1000
def generate_string():
    # Using a list comprehension to create a string of numbers from 1 to 1000
    return ''.join(str(i) for i in range(1, 1001))

def main():
    # Reading an integer input from the user
    n = int(sys.stdin.readline().strip())
    
    # Printing the character at the (n-1)th index of the generated string
    print(generate_string()[n - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
