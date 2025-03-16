x, y = map(int, input().split())  # Read two integers from standard input
if abs(x - y) <= 1:
    print("Brown")  # Check if the absolute difference is less than or equal to 1
else:
    print("Alice")  # Otherwise, print "Alice"
# <END-OF-CODE>
