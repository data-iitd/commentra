
x, y = map(int, input().split())  # Read two integers from standard input and store them in variables x and y
if abs(x-y) <= 1: print("Brown")  # Check if the absolute difference is less than or equal to 1 and print "Brown"
else: print("Alice")  # Otherwise, print "Alice"

