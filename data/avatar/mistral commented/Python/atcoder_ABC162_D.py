# Import the math module to use the ceil function
import math

# Take an integer input N and a string input S from the user
N = int(input())
S = input()

# Define a function calculate that takes two arguments: an integer n and a string s
def calculate(n, s):
    # Create a list arr from the string s
    arr = list(s)

    # Count the number of occurrences of each color in the list arr and store them in variables rNum, gNum, and bNum
    rNum = arr.count("R")
    gNum = arr.count("G")
    bNum = arr.count("B")

    # Initialize a variable sum to 0
    sum = 0

    # Use a for loop to iterate through each step from 1 to the ceiling of N/2
    for step in range(1, math.ceil(n/2) + 1):
        # Inside the inner for loop, join three consecutive elements of the list arr to form a string s
        i = 0
        s = ""
        for _ in range(3):
            s += arr[i]
            i += 1

        # Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
        if s == "RGB" or s == "RBG" or s == "BGR" or s == "BRG" or s == "GBR" or s == "GRB":
            sum += 1

    # After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
    print(rNum * gNum * bNum - sum)

# Call the calculate function with the input values N and S
calculate(N, S)
