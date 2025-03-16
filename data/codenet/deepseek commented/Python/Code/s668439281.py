
import collections

# Step 1: Import the collections module
# This module provides specialized container datatypes

n = int(input())
# Step 2: Take an integer input `n`, representing the number of elements

ls = [input() for i in range(n)]    
# Step 3: Create a list `ls` by taking `n` inputs from the user

c = collections.Counter(ls)
# Step 4: Use the Counter class to count the frequency of each element in the list `ls`

count = c.most_common()[0][1]
# Step 5: Determine the most common element(s) and its count
# `most_common()[0][1]` gives the count of the most common element

ans = []
p = c.most_common()
# Step 6: Initialize an empty list `ans` to store the most common elements
# Create `p` to store elements and their counts

for i in range(len(c)):
    if p[i][1] == count:
        ans.append(p[i][0])
    else:
        break   
# Step 7: Loop through the Counter object to find all elements with the highest count
# Append these elements to the `ans` list

ans = sorted(ans)
# Step 8: Sort the `ans` list alphabetically

for i in ans:
    print(i)
# Step 9: Print the sorted elements one by one

