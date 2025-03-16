
# Function to find the minimum value among a variable number of integers
def min(n):
    if len(n) == 0:
        raise ValueError("len == 0") # Panic if no arguments are provided
    r = n[0] # Initialize result with the first element
    for i in range(1, len(n)):
        if n[i] <= r: # Update result if a smaller element is found
            r = n[i]
    return r # Return the minimum value

def main():
    H, N, A, B = map(int, input().split()) # Declare variables to store input values
    dp = [2100000000] * (H+10001) # Create a list for dynamic programming with a large initial value
    amax = 0 # Initialize variable to keep track of the maximum attack value
    for i in range(N):
        A, B = map(int, input().split()) # Read the attack value A and the cost B for each attack
        if A >= amax:
            amax = A # Update amax if the current attack value is greater than or equal to the current amax
        dp[A] = min(dp[A], B) # Update the cost for attack value A
        for j in range(A+1, H+A+1):
            dp[j] = min(dp[j], dp[j-A] + B) # Update the cost for all possible health values using the current attack
    print(min(dp[H:H+amax+1])) # Print the minimum cost to reduce health H to zero or below

