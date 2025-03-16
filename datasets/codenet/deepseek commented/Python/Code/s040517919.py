# The code starts by taking two integer inputs A and B.
A, B = map(int, input().split())

# It then checks if A is equal to B. If they are equal, it prints "Draw".
if A == B:
    print("Draw")

# If A is not equal to B, it checks if A is 1. If A is 1, it prints "Alice".
elif A == 1:
    print("Alice")

# If A is not 1, it checks if B is 1. If B is 1, it prints "Bob".
elif B == 1:
    print("Bob")

# If neither A nor B is 1, it compares A and B to determine who is greater. If A is greater, it prints "Alice"; otherwise, it prints "Bob".
elif A > B:
    print("Alice")
else:
    print("Bob")
