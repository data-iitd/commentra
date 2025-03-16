# Import the 'defaultdict' from the 'collections' module
from collections import defaultdict

# Read the number of elements in the list from user input
n = int(input())

# Initialize an empty dictionary 's' with default value 0 using defaultdict
s = defaultdict(lambda: 0)

# Create an empty list 'l' with length 'n' by reading elements from user input
l = [input() for i in range(n)]

# Initialize a flag 'f' with value 'Yes'
f = 'Yes'

# Iterate through each element 'v' in the list 'l'
for v in l:
    # Increment the count of 'v' in dictionary 's'
    s[v] += 1

    # Check if the count of 'v' in dictionary 's' is greater than or equal to 2
    if s[v] >= 2:
        # If yes, set the flag 'f' to 'No'
        f = 'No'

    # Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
    if i != -1 and l[i][-1] != v[0]:
        # If yes, set the flag 'f' to 'No'
        f = 'No'

    # Increment the index 'i'
    i += 1

# Print the final value of flag 'f'
print(f)
