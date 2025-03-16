def main():
    try:
        # Read a line of input from the console
        x = input().strip().split()
        
        # Parse the first and second elements of the array as integers
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
        # Handle any exceptions that may occur during input or processing
        pass

if __name__ == "__main__":
    main()
