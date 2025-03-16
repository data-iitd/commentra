

x, y = map(int, input().split()) # Read user inputs from standard input using input() and split()

if abs(x-y) <= 1: # Check if the absolute difference between x and y is less than or equal to 1
  print("Brown") # If the condition is true, print "Brown" to the standard output
else:
  print("Alice") # If the condition is false, print "Alice" to the standard output

