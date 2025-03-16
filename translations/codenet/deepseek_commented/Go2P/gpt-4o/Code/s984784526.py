# Declare an array of 3 integers
a = list(map(int, input().split()))

# Initialize counters for the number of 5s and 7s
five = 0
seven = 0

# Loop through the array to count the number of 5s and 7s
for num in a:
    if num == 5:
        five += 1
    if num == 7:
        seven += 1

# Check if there are exactly 2 fives and 1 seven
if five == 2 and seven == 1:
    print("YES")
else:
    print("NO")

# <END-OF-CODE>
