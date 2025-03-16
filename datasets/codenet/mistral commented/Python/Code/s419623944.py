
N, R = map(int, input().split())
# Assign user input values to variables N and R

if N >= 10:
# Check if N is greater than or equal to 10
  print(R)
# If true, print the value of R
else:
# If false, calculate the difference between 10 and N
  difference = 10 - N
# Assign the difference to a variable

  print(R + 100 * difference)
# Calculate the difference multiplied by 100 and add it to R, then print the result