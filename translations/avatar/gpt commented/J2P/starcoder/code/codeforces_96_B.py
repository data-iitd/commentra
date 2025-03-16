import sys; # Import the sys module for reading input from the user

# Read a long integer from user input
number = int(sys.stdin.readline().strip());

# Initialize variables to store the result and the current value
ans = -1;
value = 0;

# Initialize a mask variable starting from 2
mask = 2;

# Loop until the current value is less than the input number
while (value < number):
    # Convert the current mask to a binary string and remove the leading '1'
    s = bin(mask)[2:];
    
    # Initialize a counter for zeros in the binary string
    zeros = 0;
    
    # Count the number of '0's in the binary string
    for c in s:
        if (c == '0'): zeros++;
    
    # If the number of zeros is not equal to the number of ones, skip to the next iteration
    if (zeros!= s.length() - zeros): continue;
    
    # Replace '0's with '4's and '1's with '7's to form a new number
    s = s.replace('0', '4');
    s = s.replace('1', '7');
    
    # Parse the modified string as a long integer
    value = int(s, 2);

# Print the final value that meets the condition
print(value);

