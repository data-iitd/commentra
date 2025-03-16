def solve():
    pass


if __name__ == "__main__":
    # Read input values for a and b
    a, b = map(int, input().split())
    
    # Determine the outcome based on the values of a and b
    if a == 1 or b == 1:
        # Special case when either a or b is 1
        if a == 1 and b == 1:
            # Both players have 1, result is a draw
            ans = "Draw"
        elif a == 1:
            # Alice has 1, Bob wins
            ans = "Alice"
        else:
            # Bob has 1, Alice wins
            ans = "Bob"
    else:
        # General case when both a and b are greater than 1
        if a == b:
            # Both players have equal values, result is a draw
            ans = "Draw"
        elif a > b:
            # Alice has a greater value, she wins
            ans = "Alice"
        else:
            # Bob has a greater value, he wins
            ans = "Bob"

    # Output the result of the game
    print(ans)
