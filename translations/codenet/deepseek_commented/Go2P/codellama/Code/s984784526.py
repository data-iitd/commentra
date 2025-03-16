
# Declare an array of 3 integers
a = [0, 0, 0]

# Read three integers from standard input and store them in the array `a`
for i in range(3):
    a[i] = int(input())

# Initialize counters for the number of 5s and 7s
five = 0
seven = 0

# Loop through the array to count the number of 5s and 7s
for i in range(3):
    if a[i] == 5:
        five += 1
    if a[i] == 7:
        seven += 1

# Check if there are exactly 2 fives and 1 seven
if five == 2 and seven == 1:
    print("YES")
else:
    print("NO")

