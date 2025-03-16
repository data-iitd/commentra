
# Define long long type for large integers
a, b, c, d, e, f, g, T = 0, 0, 0, 0, 0, 0, 0, 0
z = ""

# Read the input string
z = input()

# Get the size of the input string
a = len(z)

# Check for consecutive identical characters in the string
for i in range(a - 1):
    # If two consecutive characters are the same, print "Bad" and exit
    if z[i] == z[i + 1]:
        print("Bad")
        exit(0)

# If no consecutive identical characters were found, print "Good"
print("Good")

