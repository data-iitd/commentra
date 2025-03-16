import sys

# Reading input strings s and t
s = input()
t = input()

# Initializing an empty list to store answers
ans = []

# Iterating through all possible substrings of s that have the same length as t
for i in range(len(s) - len(t) + 1):
    # Initializing a list to store the modified string s
    ss = list(s)

    # Checking if the current substring matches the pattern t
    f = True
    for j in range(len(t)):
        # If the current character of s does not match the current character of t or is not '?'
        if ss[i + j] != t[j] and ss[i + j] != '?':
            # Setting flag to false and breaking the loop
            f = False
            break
        else:
            # Replacing the current character of s with the corresponding character of t
            ss[i + j] = t[j]

    # If the current substring matches the pattern t
    if f:
        # Appending the modified string to the answer list
        ans.append(''.join(ss).replace('?', 'a'))

# Sorting the answer list in ascending order
ans.sort()

# Checking if the answer list is empty
if len(ans) == 0:
    # Printing "UNRESTORABLE" if the answer list is empty
    print("UNRESTORABLE")
else:
    # Printing the first element of the answer list
    print(ans[0])

