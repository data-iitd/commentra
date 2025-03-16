# Read user input and store it in variables s and t respectively.
s, t = input().split()

# Concatenate the string s with itself.
s += s

# Check if the substring t is present in the string s. If it is, print "Yes". Otherwise, print "No".
print("Yes" if t in s else "No")

# <END-OF-CODE>
