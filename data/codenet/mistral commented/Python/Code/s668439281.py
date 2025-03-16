# Import the collections module
import collections

# Ask the user for the number of strings to input
n = int(input())

# Create an empty list called ls to store the strings
ls = []

# Fill the ls list with user-input strings
ls = [input() for i in range(n)]

# Create a Counter object called c to count the occurrences of each unique string in ls
c = collections.Counter(ls)

# Find the string with the highest count and store the count and string in separate variables
count, i = c.most_common(1)[0]

# Create an empty list called ans to store the strings with the highest count
ans = []

# Iterate through the c dictionary and add each string with the highest count to the ans list
for p in c:
    if c[p] == count:
        ans.append(p)

# Sort the ans list in ascending order
ans = sorted(ans)

# Iterate through the ans list and print each string
for i in ans:
    print(i)