
s, t = input().split() # Read two strings from standard input

# Concatenate s with itself to double its length
s += s

# Check if t is a substring of the doubled s
# If found, find returns the position; otherwise, it returns -1
# Convert the result to a boolean for easy printing
print("Yes" if s.find(t)!= -1 else "No")
