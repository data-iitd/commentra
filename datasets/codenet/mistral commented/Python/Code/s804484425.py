from operator import itemgetter

# Read input number of items and the number of items to select
n, k = map(int, input().split())

# Initialize list of items with their respective deadlines
info = [list(map(int, input().split())) for i in range(n)]

# Sort the items in descending order based on their deadlines
info = sorted(info, key = itemgetter(1), reverse = True)

# Select the first 'k' items with distinct types
selected = info[0:k]
selected_only = []
selected_chohuku = []
memo = {}
for t, d in selected:
    # If the type of the item is not in the memo dictionary, add it and append its deadline to selected_only
    if t not in memo:
        memo[t] = 1
        selected_only.append(d)
    # If the type of the item is already in the memo dictionary, append its deadline to selected_chohuku
    else:
        selected_chohuku.append(d)

# Initialize memo dictionary to keep track of distinct types
cnt_type = len(memo)

# Process the remaining items and update the memo dictionary, selected_only, and selected_chohuku lists
for t, d in info[k:]:
    # If the type of the item is not in the memo dictionary, add it and append its deadline to unselected_only
    if t not in memo:
        memo[t] = 1
        unselected_only.append(d)

# Calculate the sum of deadlines of selected_chohuku and selected_only
sum_select = sum(selected_chohuku) + sum(selected_only)

# Initialize ans with the initial value of the maximum answer
ans = cnt_type*cnt_type + sum_select

# Process the remaining items and update the ans value
for i in range(min(len(selected_chohuku), len(unselected_only))):
    # Increment the number of distinct types
    cnt_type += 1
    # Add the deadline of the last unselected_only item to sum_select
    sum_select += unselected_only[-1]
    # Subtract the deadline of the last selected_chohuku item from sum_select
    sum_select -= selected_chohuku[-1]
    # Remove the last unselected_only and selected_chohuku items
    del unselected_only[-1]
    del selected_chohuku[-1]
    # Calculate the temporary answer and update the ans value if it's greater
    tmp = cnt_type*cnt_type + sum_select
    ans = max(ans, tmp)

# Print the final answer
print(ans)