# Import the necessary module for user input
import sys

def main():
    # Read a long integer from user input
    number = int(sys.stdin.readline().strip())
    
    # Initialize variables to store the result and the current value
    ans = -1
    value = 0
    
    # Initialize a mask variable starting from 2
    mask = 2
    
    # Loop until the current value is less than the input number
    while value < number:
        # Convert the current mask to a binary string and remove the leading '1'
        s = bin(mask)[2:]  # Get binary representation and strip the '0b' prefix
        mask += 1
        
        # Initialize a counter for zeros in the binary string
        zeros = 0
        
        # Count the number of '0's in the binary string
        for c in s:
            if c == '0':
                zeros += 1
        
        # If the number of zeros is not equal to the number of ones, skip to the next iteration
        if zeros != len(s) - zeros:
            continue
        
        # Replace '0's with '4's and '1's with '7's to form a new number
        s = s.replace('0', '4').replace('1', '7')
        
        # Parse the modified string as a long integer
        value = int(s)
    
    # Print the final value that meets the condition
    print(value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
