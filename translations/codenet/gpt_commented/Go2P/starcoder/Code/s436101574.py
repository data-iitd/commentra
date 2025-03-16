import sys
import re

# Initialize input and output
input = sys.stdin
output = sys.stdout

# Read the first string of runes (s)
s = input.readline().strip()
# Read the second string of runes (t)
t = input.readline().strip()

# Initialize a slice to hold possible answers
ans = []

# Iterate through the first string to find occurrences of the second string
for i in range(len(s)-len(t)+1):
	f = True # Flag to check if the current position is valid
	ss = list(s) # Create a copy of the original string
	# Check if the substring of s can match t
	for j in range(len(t)):
		# If characters do not match and are not '?', set flag to false
		if s[i+j]!= t[j] and s[i+j]!= '?':
			f = False
			break
		else:
			# Replace '?' with the corresponding character from t
			ss[i+j] = t[j]
	# If the substring matched, replace remaining '?' with 'a' and store the result
	if f:
		ans.append(''.join(ss).replace('?', 'a'))

# Sort the possible answers
ans.sort()

# Output the result: either the first valid answer or "UNRESTORABLE"
if len(ans) == 0:
	print("UNRESTORABLE")
else:
	print(ans[0])

