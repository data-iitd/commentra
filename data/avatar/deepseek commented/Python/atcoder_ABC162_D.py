import math

# Taking input for N and S
N = int(input())
S = input()

# Defining the function calculate that takes two parameters, n and s
def calculate(n, s):
    # Converting the string s into a list of characters
    arr = list(s)
    
    # Calculating the counts of 'R', 'G', and 'B'
    rNum = arr.count("R")
    gNum = arr.count("G")
    bNum = arr.count("B")
    
    # Initializing sum to 0
    sum = 0
    
    # Iterating over possible step sizes from 1 to math.ceil(n / 2) + 1
    for step in range(1, math.ceil(n / 2) + 1):
        # Iterating over possible starting indices for the substring
        for i in range(n - 2 * step):
            # Forming a substring of length 3
            s = "".join([arr[i], arr[i + step], arr[i + step * 2]])
            
            # Checking if the substring matches any of the patterns
            if s == "RGB" or s == "RBG" or s == "BGR" or s == "BRG" or s == "GBR" or s == "GRB":
                sum = sum + 1
    
    # Printing the product of the counts of 'R', 'G', and 'B' minus sum
    print(rNum * gNum * bNum - sum)

# Calling the function calculate with N and S as arguments
calculate(N, S)