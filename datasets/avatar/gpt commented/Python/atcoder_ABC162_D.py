import math

# Read the integer input N which represents the length of the string
N = int(input())

# Read the string input S which consists of characters 'R', 'G', and 'B'
S = input()

def calculate(n, s):
    # Convert the string into a list of characters for easier manipulation
    arr = list(s)
    
    # Count the occurrences of each color in the string
    rNum = arr.count("R")
    gNum = arr.count("G")
    bNum = arr.count("B")
    
    # Initialize a variable to keep track of the number of valid RGB combinations found
    sum = 0
    
    # Loop through possible steps to form combinations of three characters
    for step in range(1, math.ceil(n / 2) + 1):
        # Loop through the string to form combinations based on the current step
        for i in range(n - 2 * step):
            # Create a substring of three characters at the current indices
            s = "".join([arr[i], arr[i + step], arr[i + step * 2]])
            
            # Check if the formed substring is one of the valid RGB permutations
            if s == "RGB" or s == "RBG" or s == "BGR" or s == "BRG" or s == "GBR" or s == "GRB":
                # Increment the count of valid combinations found
                sum += 1
    
    # Calculate and print the result: total combinations minus the valid RGB combinations found
    print(rNum * gNum * bNum - sum)

# Call the calculate function with the inputs N and S
calculate(N, S)
