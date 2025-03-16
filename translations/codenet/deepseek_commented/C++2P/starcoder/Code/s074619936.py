# Include the standard library for atoi function
import sys

# Infinite loop that continues until the user inputs "0"
while(1):
    str = raw_input() # Read a string from the user
    if(str == "0"): break # If the input string is "0", break the loop
    sum = 0 # Initialize sum to 0
    for i in range(len(str)): # Loop through each character in the string
        num = int(str[i]) # Convert the character to an integer
        sum += num # Add the integer to the sum
    print sum # Print the sum

# 