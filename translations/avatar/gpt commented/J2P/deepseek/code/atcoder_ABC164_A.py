# Reading input from the console
# Note: In Python, input is read as a string by default, so we need to convert it to an integer

# Reading the first line of input
input_line = input()

# Splitting the first line into an array of strings
numlist = input_line.split(" ")

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
