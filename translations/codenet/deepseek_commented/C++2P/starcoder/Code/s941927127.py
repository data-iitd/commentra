
# Step 1: Include necessary headers
# The code starts by including necessary headers for input/output operations,
# string manipulation, and using standard namespace.
W = raw_input()

# Step 2: Read input
# The program reads a string `W` from the standard input.

# Step 3: Sort the string
# The string `W` is sorted in ascending order.
W = sorted(W)

# Step 4: Check for character pairs
# The program iterates through the sorted string, checking if each character
# is followed by its identical pair.
for i in range(0,len(W),2):
  if W[i]!= W[i+1]:
    # If a character is not followed by its pair, output "No" and exit.
    print "No"
    exit(0)

# Step 5: Output result
# If all characters are in pairs, the program outputs "Yes"; otherwise,
# it outputs "No".
print "Yes"

