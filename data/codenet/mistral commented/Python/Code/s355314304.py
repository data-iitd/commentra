
n = int(input())

# This block takes an integer as input from the user

if n % 1000 == 0:
  # This block checks if the number is divisible by 1000
  # If yes, print 0
  print(0)
else:
  # This block runs when the number is not divisible by 1000
  remainder = n % 1000  # Calculate the remainder of the number when divided by 1000
  print(1000 - remainder)  # Print the difference between 1000 and the remainder