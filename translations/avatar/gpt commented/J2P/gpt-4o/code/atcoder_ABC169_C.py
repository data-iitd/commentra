# Import the necessary module for reading input
import sys

def main():
    # Read a long integer value from the user
    a = int(input().strip())
    
    # Read a string value from the user
    b = input().strip()
    
    # Convert the string to a character array for processing
    bChar = list(b)
    
    # Initialize an empty string to build the integer representation
    bStr = ""
    
    # Loop through each character in the character array
    for char in bChar:
        # If the character is not a '.', append it to bStr
        if char != '.':
            bStr += char
    
    # Convert the built string (bStr) to an integer
    bInt = int(bStr)
    
    # Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    result = (a * bInt) // 100
    
    # Print the result to the console
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
