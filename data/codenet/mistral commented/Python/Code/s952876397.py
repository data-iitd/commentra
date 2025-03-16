# We first read the input as an integer n and a string s.
n = int(input())
s = input()

# We initialize two counters, left and left1, to 0.
left = 0
left1 = 0

# We iterate through the string s and keep track of the left parentheses using the left counter.
for i in s:
    if i == ")":
        left += 1  # Increment the left counter when we encounter a right parenthesis.
    else:
        break    # Break out of the loop when we encounter a left parenthesis.

# We initialize two more counters, right1 and left1, to 0.
right1 = 0

# We iterate through the string s from the index left to the end of the string.
for i in range(left, n):
    if s[i] == "(":
        right1 += 1  # Increment the right counter when we encounter a left parenthesis.
    elif right1 > 0:
        right1 -= 1  # Decrement the right counter when we encounter a right parenthesis.
    else:
        left1 += 1  # Increment the left1 counter when we encounter a right parenthesis without a corresponding left parenthesis.

# After the loop, we calculate the total number of left parentheses by adding left and left1.
left1 += left

# We add as many right parentheses as the number of left parentheses to balance the string.
for i in range(right1):
    s += ")"

# We prepend as many left parentheses as the number of left parentheses to balance the string.
for i in range(left1):
    s = "(" + s

# We print the balanced string.
print(s)
