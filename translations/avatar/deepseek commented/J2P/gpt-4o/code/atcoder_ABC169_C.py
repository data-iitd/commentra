# Importing the necessary modules
import sys

def main():
    a = int(input())  # Reading a long integer 'a' from the input
    b = input()       # Reading a string 'b' from the input
    
    bStr = ''.join([char for char in b if char != '.'])  # Filtering out periods from 'b'
    
    bInt = int(bStr)  # Parsing 'bStr' as an integer
    result = (a * bInt) // 100  # Calculating the result of (a * bInt) // 100
    print(result)  # Printing the result to the standard output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
