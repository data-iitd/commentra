
# Read two integer values from standard input
x = int(input())
y = int(input())

# Check if the absolute difference between x and y is less than or equal to 1
if abs(x - y) <= 1:
    # If the condition is true, output "Brown"
    print("Brown")
else:
    # If the condition is false, output "Alice"
    print("Alice")

