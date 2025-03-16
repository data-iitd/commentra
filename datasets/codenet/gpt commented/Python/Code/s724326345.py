def main():
    # Read input values A, B, C, X, and Y from the user and convert them to integers
    A, B, C, X, Y = map(int, input().split())
    
    # Initialize the minimum cost to a very large number
    ans = 10 ** 10

    # Iterate over the possible number of combined items (k) that can be made
    for k in range(max(X, Y) + 1):
        # Calculate the total cost for making k combined items
        # The cost includes:
        # - 2 * C * k for the combined items
        # - A * max(0, X - k) for the remaining items of type X
        # - B * max(0, Y - k) for the remaining items of type Y
        total = 2 * C * k + A * max(0, X - k) + B * max(0, Y - k)
        
        # Update the minimum cost if the current total is less than the previously recorded minimum
        if total < ans:
            ans = total

    # Print the minimum cost found
    print(ans)


if __name__ == "__main__":
    # Execute the main function when the script is run
    main()
