
A, B = [int(x) for x in input().split()]
# Taking two integer inputs from the user

if A < 10 and B < 10:
  # Checking if both A and B are less than 10
  print(A*B)
  # Printing the product of A and B if the condition is true
else:
  print(-1)
  # Printing -1 if the condition is false

