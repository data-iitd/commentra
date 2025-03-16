from operator import itemgetter

# Step 1: Read the number of dishes (n) and the number of dishes to select (k)
n, k = map(int, input().split())

# Step 2: Read the information about each dish (type and deliciousness)
info = [list(map(int, input().split())) for i in range(n)]

# Step 3: Sort the information based on the deliciousness in descending order
info = sorted(info, key=itemgetter(1), reverse=True)

# Step 4: Select the top k dishes
selected = info[0:k]

# Initialize lists to separate dishes by type
selected_only = []
selected_chohuku = []
unselected_only = []

# Step 5: Separate selected dishes into unique and repeated types
memo = {}
for t, d in selected:
    if t not in memo:
        memo[t] = 1
        selected_only.append(d)
    else:
        selected_chohuku.append(d)

# Step 6: Process the remaining dishes to find unique types
cnt_type = len(memo)
for t, d in info[k:]:
    if t not in memo:
        memo[t] = 1
        unselected_only.append(d)

# Step 7: Calculate the initial score
sum_select = sum(selected_chohuku) + sum(selected_only)
ans = cnt_type * cnt_type + sum_select

# Step 8: Reverse the order of unselected_only for easier popping
unselected_only = unselected_only[::-1]

# Step 9: Optimize the selection by swapping dishes
for i in range(min(len(selected_chohuku), len(unselected_only))):
    cnt_type += 1
    sum_select += unselected_only[-1]
    sum_select -= selected_chohuku[-1]
    del unselected_only[-1]
    del selected_chohuku[-1]
    tmp = cnt_type * cnt_type + sum_select
    ans = max(ans, tmp)

# Step 10: Print the maximum score
print(ans)
