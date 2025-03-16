# Define variables A, B, and K from user input
A, B, K = map(int, input().split())

# Check if the condition is true
if A + K - 1 >= B - K + 1:
    # If true, print numbers from A to B (inclusive)
    while A <= B:
        print(A)
        A += 1
else:
    i = 0
    # Print numbers from A to K (exclusive)
    while i <= K - 1:
        print(A + i)
        i += 1
    # Print numbers from B - K + 1 to B (inclusive)
    while B - K + 1 <= B:
        print(B - K + 1)
        K -= 1