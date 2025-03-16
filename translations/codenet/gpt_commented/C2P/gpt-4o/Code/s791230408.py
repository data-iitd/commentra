# Declare variables for input values and control variables
j = int(input("Enter number of test cases: "))  # Read the number of test cases

# Loop through each test case
for _ in range(j):
    # Read three integers a, b, and c
    a = int(input())
    b = int(input())
    c = int(input())

    # Initialize max to the value of a
    max_value = a
    k = 0  # k will track which number is the largest

    # Determine the maximum value among a, b, and c
    if max_value <= b:
        max_value = b  # Update max to b if b is greater
        k = 1  # Set k to indicate b is the largest
    if max_value <= c:
        max_value = c  # Update max to c if c is greater
        k = 2  # Set k to indicate c is the largest

    # Square the maximum value and the other two values
    max_value_squared = max_value * max_value
    a_squared = a * a
    b_squared = b * b
    c_squared = c * c

    # Check if the squared values satisfy the Pythagorean theorem
    if k == 0 and max_value_squared == b_squared + c_squared:
        print("YES")  # a is the largest, check if a^2 = b^2 + c^2
    elif k == 1 and max_value_squared == a_squared + c_squared:
        print("YES")  # b is the largest, check if b^2 = a^2 + c^2
    elif k == 2 and max_value_squared == a_squared + b_squared:
        print("YES")  # c is the largest, check if c^2 = a^2 + b^2
    else:
        print("NO")  # The values do not satisfy the condition

# End of the program
# <END-OF-CODE>
