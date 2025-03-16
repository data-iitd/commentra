def main():
    try:
        # Read a line of input, trim whitespace, and split it into a list of strings
        x = input().strip().split()
        
        # Parse the first and second elements of the list as integers
        a = int(x[0])
        b = int(x[1])
        
        # Calculate the value of c based on the formula: c = a - b * 2
        c = a - b * 2
        
        # If c is negative, set it to 0
        if c < 0:
            c = 0
        
        # Output the final value of c
        print(c)
    except Exception as e:
       