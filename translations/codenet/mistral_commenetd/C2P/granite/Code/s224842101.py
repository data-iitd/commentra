

# Read three pairs of numbers from the user and store them in a list of tuples
pairs = []
for i in range(3):
  a, b = map(int, input().split())
  pairs.append((a, b))

# Create a dictionary to store the count of each number
count = {}
for a, b in pairs:
  if a in count:
    count[a] += 1
  else:
    count[a] = 1
  if b in count:
    count[b] += 1
  else:
    count[b] = 1

# Calculate the product of all counts in the count dictionary
product = 1
for c in count.values():
  product *= c

# Check if the product of all counts is equal to 4
if product == 4:
  print("YES")
else:
  print("NO")

