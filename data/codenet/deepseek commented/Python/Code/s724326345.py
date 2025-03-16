def main():
    # Read input values for A, B, C, X, and Y
    A, B, C, X, Y = map(int, input().split())
    
    # Initialize the minimum cost to a very large number
    ans = 10 ** 10

    # Iterate over the range from 0 to the maximum of X and Y
    for k in range(max(X, Y) + 1):
        # Calculate the total cost for k sets of both types of sushi
        total = 2 * C * k + A * max(0, X - k) + B * max(0, Y - k)
        
        # Update the minimum cost if the current total is less than the current minimum
        if total < ans:
            ans = total

    # Print the minimum cost found
    print(ans)


if __name__ == "__main__":
    main()
