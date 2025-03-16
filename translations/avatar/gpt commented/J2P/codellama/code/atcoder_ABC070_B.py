import sys 
import math 

# Set up input and output streams
inputStream = sys.stdin 
outputStream = sys.stdout 
in = inputStream.readline 
out = outputStream.write 

# Read four integers from input
a, b, c, d = map(int, in().split()) 

# Check conditions to determine the output
if c > b: 
    # If c is greater than b, output 0
    out("0\n") 
elif a > d: 
    # If a is greater than d, output 0
    out("0\n") 
elif a < c: 
    # If a is less than c, calculate and output the difference
    out(str(min(b, d) - c) + "\n") 
else: 
    # Create a list to hold the four integers
    l = [a, b, c, d] 
    
    # Sort the list to find the second largest and third largest values
    l.sort() 
    
    # Output the difference between the second largest and third largest values
    out(str(l[2] - l[1]) + "\n") 

# End of code
