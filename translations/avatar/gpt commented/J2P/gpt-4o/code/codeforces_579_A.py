# Importing the necessary modules
import sys

def main():
    # Reading an integer input from the user
    n = int(input())
    
    # Initializing an empty string to store the binary representation
    s = ""
    
    # Converting the integer n to its binary representation
    while n > 0:
        x = n % 2  # Getting the least significant bit (0 or 1)
        n //= 2    # Dividing n by 2 to process the next bit
        s += str(x)  # Appending the bit to the binary string
    
    # Initializing a counter to count the number of '1's in the binary representation
    ans = 0
    
    # Iterating through the binary string to count '1's
    for char in s:
        if char == '1':  # Checking if the current character is '1'
            ans += 1  # Incrementing the count of '1's
    
    # Printing the total count of '1's in the binary representation
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
