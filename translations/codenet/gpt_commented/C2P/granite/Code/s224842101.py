
# Read pairs of integers and update their counts
for i in range(3):
    a, b = map(int, input().split())
    count[a - 1] += 1
    count[b - 1] += 1

# Initialize the product variable
s = 1
# Calculate the product of counts
for i in range(4):
    s *= count[i]

# Check if the product equals 4, indicating each number appears at least once
if s == 4:
    print("YES")  # Output YES if all numbers are present
else:
    print("NO")   # Output NO if any number is missing

