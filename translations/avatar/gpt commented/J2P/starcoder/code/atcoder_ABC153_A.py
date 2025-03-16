
# <START-OF-CODE>

# Create a BufferedReader to read input from the console
in = raw_input()

# Read a line of input and split it into an array of strings
str = in.split(" ")

# Parse the first string as an integer representing the initial health
h = int(str[0])

# Parse the second string as an integer representing the damage dealt per attack
a = int(str[1])

# Initialize a counter to keep track of the number of attacks
num = 0

# Loop until the health is greater than zero
for i in range(1, h):
    # Decrease health by the amount of damage dealt
    h = h - a

    # Increment the attack counter
    num = num + 1

# Output the total number of attacks required to reduce health to zero or below
print num

# 