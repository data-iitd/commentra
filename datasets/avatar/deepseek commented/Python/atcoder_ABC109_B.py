from collections import defaultdict

# Step 1: Import the defaultdict class from the collections module.
# This is used to create a dictionary where the default value for any key is 0.

n = int(input())  # Step 2: Take an integer input n which represents the number of strings.
s = defaultdict(lambda: 0)  # Step 3: Initialize a defaultdict named s with a default value of 0.
l = [input() for i in range(n)]  # Step 4: Create a list l by taking n inputs from the user.
f = 'Yes'  # Step 5: Initialize a variable f to 'Yes' to keep track of the validity of the sequence.
i = -1  # Step 6: Initialize a variable i to -1 to keep track of the index of the current string in the list.

# Step 7: Enter a for loop to iterate over each string v in the list l.
for v in l:
    s[v] += 1  # Step 8: Increment the count of the current string v in the dictionary s.
    if s[v] >= 2:  # Step 9: If the count of v becomes 2 or more, set f to 'No'.
        f = 'No'
    if i != -1 and l[i][-1] != v[0]:  # Step 10: If i is not -1 and the last character of the previous string is not the same as the first character of the current string, set f to 'No'.
        f = 'No'
    i += 1  # Step 11: Increment the index i after processing each string.

# Step 12: Print the value of f, which indicates whether the sequence is valid or not.
print(f)
