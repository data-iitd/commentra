# Read three integers A, B, and K from user input
A, B, K = map(int, input().split())

# Check if the range from A to B can accommodate K elements
if A + K - 1 >= B - K + 1:
    # If the condition is true, print all integers from A to B
    while A <= B:
        print(A)  # Print the current value of A
        A += 1    # Increment A to move to the next integer
else:
    # If the condition is false, print the first K integers starting from A
    i = 0
    while i <= K - 1:
        print(A + i)  # Print the current value of A + i
        i += 1        # Increment i to move to the next integer

    # Print the last K integers starting from B - K + 1
    while B - K + 1 <= B:
        print(B - K + 1)  # Print the current value of B - K + 1
        K -= 1            # Decrement K to move to the previous integer
