
# Create a Scanner object to read input from the user
in = Scanner(System.in)

# Read the input string from the user
s = in.next()

# Convert the input string to a character array
targ = s.toCharArray()

# Initialize a HashMap to store the frequency of each character
map = HashMap()

# Loop through each character in the array
for i in range(len(targ)):
    # If the character is not already in the map, add it with a count of 1
    if not map.containsKey(targ[i]):
        map.put(targ[i], 1)
    else:
        # If the character is already in the map, increment its count
        map.put(targ[i], map.get(targ[i]) + 1)

# Initialize a boolean variable to check if the conditions are met
ok = True

# Check if each character appears exactly twice
for c in map.entrySet():
    if c.getValue()!= 2:
        ok = False # Set ok to false if any character does not appear twice
        break

# Check if there are exactly two unique characters that appear twice
if ok and map.size() == 2:
    print("Yes") # Output "Yes" if conditions are satisfied
else:
    print("No") # Output "No" if conditions are not satisfied

# Close the scanner to prevent resource leaks
in.close()

