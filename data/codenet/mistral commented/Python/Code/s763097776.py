# Take user input for the number of elements in the list `n`
n = int(input())

# Take user input for the list `p` itself
p = [int(x) for x in input().split()]

# Create a copy of the list `p` for later use
p_copy = p[:]

# Sort the list `p` in ascending order
p.sort()

# Initialize a counter `count` to 0
count = 0

# Iterate through each index `i` in the list `p`
for i in range(n):
    # If the element at index `i` in the original list `p` is not equal to the corresponding element in the copied list `p_copy`, we increment the counter `count` by 1
    if p[i] != p_copy[i]:
        count += 1

# Check the value of `count`
if count == 0:
    # If all elements in the original list were equal to their corresponding elements in the copied list, the list was sorted in the first place
    print("YES")
elif count == 2:
    # If there were exactly two elements that were not equal, the minimum number of elements required for an unsorted list with length `n`
    print("YES")
else:
    # If neither of the above conditions are met, the list is not sorted
    print("NO")
