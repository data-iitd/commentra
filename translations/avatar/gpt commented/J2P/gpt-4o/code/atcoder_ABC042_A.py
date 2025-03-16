def main():
    # Read a line of input and split it into a list of strings
    line = input()
    lst = line.split()
    
    # Parse the first three elements of the input into integers
    x = int(lst[0])
    a = int(lst[1])
    y = int(lst[2])
    
    # Initialize a variable to hold the result, defaulting to "NO"
    h = "NO"
    
    # Check if any of the numbers x, a, or y are either 5 or 7
    if x == 5 or x == 7 or a == 5 or a == 7 or y == 5 or y == 7:
        # If the sum of x, a, and y equals 17, set the result to "YES"
        if x + y + a == 17:
            h = "YES"
    
    # Output the result
    print(h)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
