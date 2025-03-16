# Step 1: Read the number of test cases (j) from the user input.
j = int(input())

for _ in range(j):
    # Step 3: For each test case, read three integers (a, b, c).
    a = int(input())
    b = int(input())
    c = int(input())

    # Step 4: Determine the maximum of the three integers.
    max_value = a
    k = 0
    if max_value <= b:
        max_value = b
        k = 1
    if max_value <= c:
        max_value = c
        k = 2

    # Step 5: Calculate the square of the maximum and the squares of a, b, and c.
    max_value = max_value * max_value
    a = a * a
    b = b * b
    c = c * c

    # Step 6: Check if the square of the maximum is equal to the sum of the squares of the other two integers.
    if k == 0 and max_value == b + c:
        print("YES")
    elif k == 1 and max_value == a + c:
        print("YES")
    elif k == 2 and max_value == a + b:
        print("YES")
    else:
        print("NO")

# <END-OF-CODE>
