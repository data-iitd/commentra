
# Declare three integer variables to hold the input values
a, b, c = int(input()), int(input()), int(input())

# Check if the number formed by a, b, and c is divisible by 4
# The number is formed as 100*a + 10*b + c
if ((100 * a + 10 * b + c) % 4 == 0):
    # If the number is divisible by 4, output "YES"
    print("YES")
else:
    # If the number is not divisible by 4, output "NO"
    print("NO")

