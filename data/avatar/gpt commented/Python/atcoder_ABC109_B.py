from collections import defaultdict

# Read the number of strings to be processed
n = int(input())

# Initialize a defaultdict to count occurrences of each string
s = defaultdict(lambda: 0)

# Read n strings into a list
l = list([input() for i in range(n)])

# Initialize a flag to determine if the conditions are met
f = 'Yes'

# Initialize an index variable to track the previous string
i = -1

# Iterate through each string in the list
for v in l:
    # Increment the count for the current string
    s[v] += 1
    
    # Check if the current string has appeared more than once
    if s[v] >= 2:
        f = 'No'  # Set flag to 'No' if a duplicate is found
    
    # Check if the previous string's last character does not match the current string's first character
    if i != -1 and l[i][-1] != v[0]:
        f = 'No'  # Set flag to 'No' if the character condition is violated
    
    # Update the index to the current string's index
    i += 1

# Print the final result based on the checks
print(f)
