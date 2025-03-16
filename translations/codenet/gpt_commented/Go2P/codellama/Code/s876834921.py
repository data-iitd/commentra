
# Declare a string variable to hold user input
s = input()

# Replace occurrences of "dream" with "D"
s = s.replace("dream", "D")

# Replace occurrences of "erase" with "E"
s = s.replace("erase", "E")

# Remove occurrences of "Der" from the string
s = s.replace("Der", "")

# Remove occurrences of "Er" from the string
s = s.replace("Er", "")

# Remove occurrences of "D" from the string
s = s.replace("D", "")

# Remove occurrences of "E" from the string
s = s.replace("E", "")

# Trim any leading or trailing whitespace from the string
s = s.strip()

# Check if the resulting string is empty
if s == "":
    # If the string is empty, print "YES"
    print("YES")
else:
    # If the string is not empty, print "NO"
    print("NO")

