# Define the function to solve the problem
def solve():
    # Read input values from the user
    a, b = map(int, input().split())

    # Determine the answer based on the input values
    if a == 1 and b == 1:
        # Both a and b are equal to 1, so the answer is a draw
        ans = "Draw"
    elif a == 1:
        # a is equal to 1, so the answer is Alice
        ans = "Alice"
    else:
        # Neither a nor b is equal to 1, so the answer is Bob
        ans = "Bob"

    # Print the answer to the console
    print(ans)

# Call the solve function to solve the problem
solve()

# <END-OF-CODE>
