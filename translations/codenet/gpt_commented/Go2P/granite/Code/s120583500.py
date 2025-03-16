
# Declare a variable to hold the input string
s = input()

# Initialize a counter for consecutive valid characters and a list to hold counts
count = 0
counter = []

# If the input string is empty, exit the function
if s == "":
    exit()

# Start the counter with an initial value of 0
counter.append(0)
# Split the input string into a list of individual characters
li = list(s)

# Iterate over each character in the list
for s in li:
    # Check if the character is one of the valid DNA bases
    if s == "A" or s == "C" or s == "G" or s == "T":
        # Increment the count for consecutive valid characters
        count += 1
    else:
        # If an invalid character is encountered, store the current count
        counter.append(count)
        # Reset the count for the next sequence
        count = 0

# Append the count of the last sequence of valid characters
counter.append(count)
# Sort the counts to find the maximum consecutive valid characters
counter.sort()
# Print the maximum count of consecutive valid characters
print(counter[-1])

