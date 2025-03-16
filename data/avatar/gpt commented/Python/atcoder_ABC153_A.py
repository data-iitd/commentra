# Read two integers from input: h (height) and a (height per shoe)
h, a = map(int, input().split(" "))

# Calculate the number of shoes needed by performing integer division
sho = int(h / a)

# Calculate the remaining height after accounting for full shoes
am = int(h % a)

# If there is any remaining height, we need one additional shoe
if am != 0:
    sho += 1  # Increment the shoe count by 1 for the remaining height
else:
    pass  # No additional shoe needed if there is no remaining height

# Print the total number of shoes required
print(sho)
