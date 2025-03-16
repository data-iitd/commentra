# Declare variables for input and a map to store string entries
n = int(input()) # Number of commands to process
str = [0] * 10 # Arrays to hold command and string inputs
com = [0] * 13
T = {} # Map to track the presence of strings (true if present)

# Loop through each command
for i in range(n):
    # Read the command and the associated string
    com, str = input().split()
    
    # Check if the command is 'insert' (indicated by the first character being 'i')
    if com[0] == 'i':
        # Insert the string into the map with a value of true
        T[str] = True
    else:
        # If the command is not 'insert', check if the string exists in the map
        if str in T:
            # If the string exists, print "yes"
            print("yes")
        else:
            # If the string does not exist, print "no"
            print("no")

# Return 0 to indicate successful execution
0

