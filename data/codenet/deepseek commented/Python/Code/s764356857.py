
A, B = map(int, input().split())

# Take two integers A and B as input

min = B * 10
max = (B+1) * 10 -1

# Calculate the minimum and maximum possible values for the price

ans = -1
# Initialize the variable ans to -1

for i in range(min, max+1):
  # Iterate over the range from min to max
  if int(i * 0.08) == A:
    # Check if multiplying the value by 0.08 and converting it to an integer gives A
    ans = i
    # If the condition is met, set ans to the current value
    break

print(ans)
# Print the value of ans

