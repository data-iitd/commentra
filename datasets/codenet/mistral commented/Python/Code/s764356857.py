# Taking two integers A and B as input from the user
A, B = map(int, input().split())

# Calculating the minimum and maximum values for the loop based on the value of B
min = B * 10
max = (B+1) * 10 -1

# Initializing the variable ans to -1
ans = -1

# Iterating through the range of numbers from the minimum to the maximum
for i in range(min, max+1):
  # Checking if the integer value obtained by multiplying the current number with 0.08 is equal to A
  if int(i * 0.08) == A:
    # If the condition is true, assigning the current number to the variable ans and breaking out of the loop
    ans = i
    break

# Printing the value of ans
print(ans)
