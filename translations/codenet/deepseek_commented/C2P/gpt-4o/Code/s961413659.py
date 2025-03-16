# Read two integers from the user input
a, b = map(int, input().split())

# Check if either of the integers is 1, and if so, change them to 14
if a == 1:
    a = 14
if b == 1:
    b = 14

# Compare the two integers and print the appropriate result
if a < b:
    print("Bob")
elif a > b:
    print("Alice")
else:
    print("Draw")

# <END-OF-CODE>
