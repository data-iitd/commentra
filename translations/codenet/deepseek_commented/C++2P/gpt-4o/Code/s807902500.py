s, t = input().split()  # Read two strings from standard input

# Concatenate s with itself to double its length
s += s

# Check if t is a substring of the doubled s
# If found, 'in' returns True; otherwise, it returns False
print("Yes" if t in s else "No")

# <END-OF-CODE>
