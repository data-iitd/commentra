# Declare four integer variables to hold input values
a, b, c, d = int(input()), int(input()), int(input()), int(input())

# Check if the product of a and b is odd and the sum of c and d is odd
if (a * b) % 2 == 1 and (c + d) % 2 == 1:
    # If both conditions are true, output "No"
    print("No")
else:
    # If either condition is false, output "Yes"
    print("Yes")

