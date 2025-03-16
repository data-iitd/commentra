# <START-OF-CODE>

# Read the number of test cases
j = int(input())

# Loop through each test case
for i in range(j):
    # Read three integers a, b, and c
    a, b, c = map(int, input().split())

    # Initialize max to the value of a
    max = a
    k = 0 # k will track which number is the largest

    # Determine the maximum value among a, b, and c
    if max <= b:
        max = b # Update max to b if b is greater
        k = 1 # Set k to indicate b is the largest
    if max <= c:
        max = c # Update max to c if c is greater
        k = 2 # Set k to indicate c is the largest

    # Square the maximum value and the other two values
    max = max * max
    a = a * a
    b = b * b
    c = c * c

    # Check if the squared values satisfy the Pythagorean theorem
    if k == 0 and max == b + c:
        print("YES") # a is the largest, check if a^2 = b^2 + c^2
    elif k == 1 and max == a + c:
        print("YES") # b is the largest, check if b^2 = a^2 + c^2
    elif k == 2 and max == a + b:
        print("YES") # c is the largest, check if c^2 = a^2 + b^2
    else:
        print("NO") # The values do not satisfy the condition

# 