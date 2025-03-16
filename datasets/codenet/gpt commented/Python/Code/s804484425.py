from operator import itemgetter

# Read the number of items (n) and the number of selections (k) from input
n, k = map(int, input().split())

# Read the information for each item, where each item has a type and a value
info = [list(map(int, input().split())) for i in range(n)]

# Sort the items based on their values in descending order
info = sorted(info, key=itemgetter(1), reverse=True)

# Select the top k items based on their values
selected = info[0:k]

# Initialize lists to hold selected and unselected values
selected_only = []      # Values of selected items with unique types
selected_chohuku = []   # Values of selected items with duplicate types
unselected_only = []    # Values of unselected items with unique types

# Dictionary to track the types of selected items
memo = {}
for t, d in selected:
    # If the type is not already in the memo, add it and store the value
    if t not in memo:
        memo[t] = 1
        selected_only.append(d)  # Add value to selected_only
    else:
        selected_chohuku.append(d)  # Add value to selected_chohuku for duplicates

# Count the number of unique types in the selected items
cnt_type = len(memo)

# Process the unselected items to find unique types and their values
for t, d in info[k:]:
    if t not in memo:
        memo[t] = 1
        unselected_only.append(d)  # Add value to unselected_only

# Calculate the initial answer based on the number of unique types and selected values
sum_select = sum(selected_chohuku) + sum(selected_only) 
ans = cnt_type * cnt_type + sum_select

# Reverse the list of unselected values for easier processing
unselected_only = unselected_only[::-1]

# Iterate to maximize the answer by replacing selected duplicates with unselected values
for i in range(min(len(selected_chohuku), len(unselected_only))):
    cnt_type += 1  # Increase the count of unique types
    sum_select += unselected_only[-1]  # Add the value of the unselected item
    sum_select -= selected_chohuku[-1]  # Remove the value of the selected duplicate
    del unselected_only[-1]  # Remove the last unselected item
    del selected_chohuku[-1]  # Remove the last selected duplicate
    # Calculate the temporary answer and update the maximum answer if necessary
    tmp = cnt_type * cnt_type + sum_select
    ans = max(ans, tmp)

# Print the final answer
print(ans)
