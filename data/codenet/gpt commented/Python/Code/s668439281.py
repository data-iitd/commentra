import collections  # Import the collections module to use Counter

# Read the number of strings to be inputted
n = int(input())

# Read n strings from user input and store them in a list
ls = [input() for i in range(n)]    

# Create a Counter object to count the occurrences of each string in the list
c = collections.Counter(ls)

# Get the highest count of occurrences from the Counter
count = c.most_common()[0][1]

# Initialize an empty list to store the most common strings
ans = []

# Get the list of most common elements from the Counter
p = c.most_common()

# Iterate through the list of most common elements
for i in range(len(c)):
    # If the count of the current element matches the highest count
    if p[i][1] == count:
        # Append the element to the answer list
        ans.append(p[i][0])
    else:
        # Break the loop if the count is less than the highest count
        break   

# Sort the answer list alphabetically
ans = sorted(ans)

# Print each of the most common strings
for i in ans:
    print(i)
