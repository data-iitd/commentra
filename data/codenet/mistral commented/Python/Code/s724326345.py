# Define the main function
def main():
    # Read input values A, B, C, X, and Y as integers
    A, B, C, X, Y = map(int, input().split())

    # Initialize the answer with a large value
    ans = 10 ** 10

    # Iterate through possible values of k
    for k in range(max(X, Y) + 1):
        # Calculate the total cost for a given value of k
        total = 2 * C * k + A * max(0, X - k) + B * max(0, Y - k)

        # If the total cost is less than the current answer, update the answer
        if total < ans:
            ans = total

    # Print the final answer
    print(ans)

# Run the main function if the script is executed directly
if __name__ == "__main__":
    main()
