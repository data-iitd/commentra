import sys

# Read the number of sweet items (N) and the initial amount of money (x)
N, x = map(int, input().split())

# Initialize a list to store the sweetness values of the items
sweet = []

# Read the sweetness values and add them to the list
for i in range(N):
    a = int(input())
    sweet.append(a)

# Sort the list of sweetness values in ascending order
sweet.sort()

# Initialize a counter for the number of sweet items that can be bought
num = 0

# Iterate through the sorted sweetness values
for i in range(N):
    # Check if the current sweetness value can be bought with the remaining money
    if x - sweet[num] >= 0:
        # Deduct the sweetness value from the total money
        x = x - sweet[num]
        # Increment the count of items bought
        num += 1
    else:
        # If the current item cannot be bought, exit the loop
        break

# Adjust the count if all items were bought but there is still money left
if (num == N) and (x > 0):
    num -= 1

# Print the total number of sweet items that can be bought
print(num)

