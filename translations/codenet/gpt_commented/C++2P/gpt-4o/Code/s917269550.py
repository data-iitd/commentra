# Declare two long long integer variables to store input values
x, y = map(int, input().split())

# Check if the absolute difference between x and y is less than or equal to 1
if abs(x - y) <= 1:
    # If the condition is true, output "Brown"
    print("Brown")
else:
    # If the condition is false, output "Alice"
    print("Alice")

# Return 0 to indicate successful execution
# <END-OF-CODE>
