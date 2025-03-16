
```python
# Read the number of strings to be processed
N = int(input())

# Initialize a dictionary to store the strings with their corresponding indices
map = {}

# Read N strings from the input and store them in the map
for i in range(N):
    map[i] = input()

# Initialize a boolean variable to track if the conditions are met
ans = True

# Initialize a dictionary to keep track of previously seen strings
past = {}

# Variable to hold the last character of the previous string
next = ""

# Iterate through the strings to check the conditions
for i in range(N):
    # Check if the current string has already been seen
    if map[i] in past.values():
        ans = False # Set answer to false if a duplicate is found
        break
    # Store the current string in the past map
    past[i] = map[i]
    # Check if this is not the first string
    if i!= 0:
        # Check if the first character of the current string matches the last character of the previous string
        if not next.endswith(map[i][0]):
            ans = False # Set answer to false if the characters do not match
            break
    # Update 'next' to the last character of the current string
    next = map[i][-1]

# Output the result based on the value of ans
if ans:
    print("Yes") # Print "Yes" if all conditions are satisfied
else:
    print("No") # Print "No" if any condition fails
```
