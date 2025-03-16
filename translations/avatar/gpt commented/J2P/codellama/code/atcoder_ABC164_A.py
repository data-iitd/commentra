import sys

# Creating a list to store the input strings
scList = []

# Continuously read input lines until an exception occurs (e.g., EOF)
for i in range(0, 1000000000):
    try:
        # Adding the input line to the list
        scList.append(sys.stdin.readline().strip())
    except:
        # Break the loop if an exception occurs (e.g., no more input)
        break

# Splitting the first line of input into a list of strings
numlist = scList[0].split(" ")

# Parsing the first number as the count of sheep
Sheep = int(numlist[0])

# Parsing the second number as the count of wolves
Wolve = int(numlist[1])

# Checking if the number of wolves is greater than or equal to the number of sheep
if Wolve >= Sheep:
    # If wolves are greater than or equal to sheep, it's unsafe
    print("unsafe")
else:
    # If wolves are fewer than sheep, it's safe
    print("safe")

# 