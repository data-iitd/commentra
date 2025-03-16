import sys

# Reading input from stdin
lines = sys.stdin.readlines()

# Parsing the first line of input into an array of strings
numlist = lines[0].split(" ")

# Parsing the first number as the count of sheep
Sheep = int(numlist[0])

# Parsing the second number as the count of wolves
Wolve = int(numlist[1])

# Checking if the number of wolves is greater than or equal to the number of sheep
if (Wolve >= Sheep):
    # If wolves are greater than or equal to sheep, it's unsafe
    print("unsafe")
else:
    # If wolves are fewer than sheep, it's safe
    print("safe")

# 