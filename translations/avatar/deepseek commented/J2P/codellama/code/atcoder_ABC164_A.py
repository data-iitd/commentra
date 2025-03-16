
import sys

# Initialize Scanner to read input
sc = sys.stdin

# Create an ArrayList to store input lines
scList = []

# Continuously read input lines from the user until an exception occurs
for i in range(0, 1000000000):
    try:
        scList.append(sc.readline())
    except:
        break

# Get the first line of input and split it into an array of strings
numlist = scList[0].split(" ")

# Parse the first element to get the number of sheep
Sheep = int(numlist[0])

# Parse the second element to get the number of wolves
Wolve = int(numlist[1])

# Check if the number of wolves is greater than or equal to the number of sheep
if Wolve >= Sheep:
    print("unsafe")
else:
    print("safe")

# 