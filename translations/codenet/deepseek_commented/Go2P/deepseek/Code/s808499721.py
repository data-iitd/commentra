# Read an integer input from the user
x = int(input())

# Initialize the answer variable to 0
ans = 0

# Check the range of x and assign the corresponding value to ans
if x >= 400 and x <= 599:
    ans = 8
elif x >= 600 and x <= 799:
    ans = 7
elif x >= 800 and x <= 999:
    ans = 6
elif x >= 1000 and x <= 1199:
    ans = 5
elif x >= 1200 and x <= 1399:
    ans = 4
elif x >= 1400 and x <= 1599:
    ans = 3
elif x >= 1600 and x <= 1799:
    ans = 2
elif x >= 1800 and x <= 9999:
    ans = 1

# Print the value of ans
print(ans)
