
n = int(input())

# Read an integer from the user

if n % 1000 == 0:
  # Check if n is divisible by 1000
  print(0)
  # If n is divisible by 1000, print 0
else:
  print(1000 - n % 1000)
  # If n is not divisible by 1000, calculate and print the difference

