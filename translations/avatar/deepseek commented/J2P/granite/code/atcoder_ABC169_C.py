

import sys # Importing sys module

def main():
    a = int(input()) # Reading an integer 'a' from the standard input stream
    b = input() # Reading a string 'b' from the standard input stream
    
    bStr = "" # Initializing an empty string to store the filtered characters of 'b'
    for char in b:
        if char!= '.':
            bStr += char # Appending non-period characters to 'bStr'
    
    bInt = int(bStr) # Parsing 'bStr' as an integer
    result = (a * bInt) // 100 # Calculating the result of (a * bInt) / 100
    print(result) # Printing the result to the standard output stream

if __name__ == "__main__":
    main() # Calling the main function

