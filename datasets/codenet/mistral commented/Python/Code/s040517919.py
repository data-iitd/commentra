A, B = map(int, input().split())
# Use map function to convert input string into two integers, A and B

if A == B:
# Check if A is equal to B
  print("Draw")
# Output string "Draw" if condition is true
elif A == 1:
# Check if A is equal to 1
  print("Alice")
# Output string "Alice" if condition is true
elif B == 1:
# Check if B is equal to 1
  print("Bob")
# Output string "Bob" if condition is true
elif A > B:
# Check if A is greater than B
  print("Alice")
# Output string "Alice" if condition is true
else:
# None of the previous conditions are true
  print("Bob")
# Output string "Bob" if no condition is true