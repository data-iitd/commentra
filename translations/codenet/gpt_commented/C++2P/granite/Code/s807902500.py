
s, t = input().split() # Read input strings s and t from the user
s = s + s # Concatenate string s with itself, effectively doubling it

# Check if string t can be found within the doubled string s
# If found, print "Yes", otherwise print "No"
print("Yes" if t in s else "No")

