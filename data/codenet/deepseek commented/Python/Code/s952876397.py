
n = int(input())
s = input()

# Read the length of the string `s`
# Read the string `s` itself

left = 0
for i in s:
    if i == ")":
        left += 1
    else:
        break

# Calculate the number of consecutive left parentheses at the beginning of the string `s`

left1 = 0
right1 = 0

for i in range(left, n):
    if s[i] == "(":
        right1 += 1
    elif right1 > 0:
        right1 -= 1
    else:
        left1 += 1

# Calculate the number of unbalanced parentheses (i.e., more closing parentheses than opening ones) and the number of unbalanced parentheses at the end of the string `s`

left1 += left
for i in range(right1):
    s += ")"
for i in range(left1):
    s = "(" + s

# Adjust the string `s` to balance the parentheses by adding the necessary parentheses at the beginning and the end

print(s)

# Print the balanced string `s`

