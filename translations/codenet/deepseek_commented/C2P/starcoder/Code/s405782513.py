# Step 1: Read three integers from input.
c = [int(x) for x in input().split()]

# Step 2: Initialize an array to keep track of the cards.
card = [0] * 10

# Step 3: Loop through the cards and mark them in the array.
for i in c:
	card[i - 1] = 1

# Step 4: Check which cards can be added to the sum without exceeding 20.
count = 0
for i in range(10):
	if card[i] == 0 and sum(c) + i + 1 <= 20:
		count += 1

# Step 5: Determine if at least 4 such cards exist.
if count >= 4:
	# Step 6: Print "YES" if such cards exist.
	print("YES")
else:
	# Step 7: Print "NO" otherwise.
	print("NO")

# 