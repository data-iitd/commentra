
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of strings to be processed
N = sc.nextInt()

# Initialize a HashMap to store the strings with their corresponding indices
map = {}

# Read N strings from the input and store them in the map
for i in range(N):
    map[i] = sc.next()

# Initialize a boolean variable to track if the conditions are met
ans = True

# Initialize a HashMap to keep track of previously seen strings
past = {}

# Variable to hold the last character of the previous string
next = ""

# Iterate through the strings to check the conditions
for i in range(N):
    # Check if the current string has already been seen
    if past.values().count(map[i]) > 0:
        ans = False # Set answer to false if a duplicate is found
        break

    # Store the current string in the past map
    past[i] = map[i]

    # Check if this is not the first string
    if i!= 0:
        # Check if the first character of the current string matches the last character of the previous string
        if not next.equals(map[i][0]):
            ans = False # Set answer to false if the characters do not match
            break

    # Update 'next' to the last character of the current string
    next = map[i][len(map[i]) - 1]

# Output the result based on the value of ans
if ans:
    print("Yes") # Print "Yes" if all conditions are satisfied
else:
    print("No") # Print "No" if any condition fails

# 