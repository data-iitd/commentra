# Read input strings s and t from the user
s, t = input().split()

# Concatenate string s with itself, effectively doubling it
s += s

# Check if string t can be found within the doubled string s
# If found, print "Yes", otherwise print "No"
print("Yes" if t in s else "No")

# <END-OF-CODE>
