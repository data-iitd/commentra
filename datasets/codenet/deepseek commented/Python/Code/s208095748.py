
A, B, C = map(int, input().split())
# Taking three integer inputs from the user

if B < C:
  # If B is less than C, print 0
  print(0)
elif A * C < B:
  # If B is not less than C, check if A times C is less than B
  print(C)
  # If A times C is less than B, print C
else:
  # If neither of the above conditions is true
  print(B//A)
  # Print the integer division of B by A

