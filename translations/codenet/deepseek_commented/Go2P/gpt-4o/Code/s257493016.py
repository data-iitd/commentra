def min_value(*args):
    if len(args) == 0:
        raise ValueError("len == 0")  # Raise an error if no arguments are provided
    r = args[0]  # Initialize result with the first element
    for i in range(1, len(args)):
        if args[i] <= r:  # Update result if a smaller element is found
            r = args[i]
    return r  # Return the minimum value

def main():
    H, N = map(int, input().split())  # Read the values of H and N from standard input
    dp = [2100000000] * (H + 10001)  # Create a list for dynamic programming with a large initial value
    amax = 0  # Initialize variable to keep track of the maximum attack value
    for _ in range(N):
        A, B = map(int, input().split())  # Read the attack value A and the cost B for each attack
        if A >= amax:
            amax = A  # Update amax if the current attack value is greater than or equal to the current amax
        dp[A] = min_value(dp[A], B)  # Update the cost for attack value A
        for j in range(A + 1, H + A + 2):
            dp[j] = min_value(dp[j], dp[j - A] + B)  # Update the cost for all possible health values using the current attack
    print(min_value(*dp[H:H + amax + 1]))  # Print the minimum cost to reduce health H to zero or below

if __name__ == "__main__":
    main()

# <END-OF-CODE>
