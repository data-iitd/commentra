
s = list(str(input()))  # Take input, convert to list of characters, and sort the list
s.sort()

# Check if the first two characters are the same and the last two characters are the same, but the first and last characters are different
if s[0] == s[1] and s[0] != s[2] and s[2] == s[3]:
    print("Yes")
else:
    print("No")

