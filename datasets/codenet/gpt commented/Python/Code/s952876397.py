# Read the length of the string and the string itself from input
n = int(input())
s = input()

# Initialize a counter for the number of closing parentheses found at the start
left = 0
# Count the number of closing parentheses at the beginning of the string
for i in s:
    if i == ")":
        left += 1  # Increment the counter for each closing parenthesis
    else:
        break  # Stop counting when we encounter the first opening parenthesis

# Initialize counters for unmatched opening and closing parentheses
left1 = 0
right1 = 0

# Iterate through the string starting from the position after the counted closing parentheses
for i in range(left, n):
    if s[i] == "(":
        right1 += 1  # Increment the counter for each opening parenthesis
    elif right1 > 0:
        right1 -= 1  # Match an opening parenthesis with a closing one
    else:
        left1 += 1  # Increment the counter for unmatched closing parentheses

# Add the counted closing parentheses to the total unmatched opening parentheses
left1 += left

# Append the necessary closing parentheses to balance the string
for i in range(right1):
    s += ")"  # Add closing parentheses for unmatched opening ones

# Prepend the necessary opening parentheses to balance the string
for i in range(left1):
    s = "(" + s  # Add opening parentheses for unmatched closing ones

# Output the balanced string
print(s)
