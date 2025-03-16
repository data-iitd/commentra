import sys

MOD = 998244353  # Modulus value for modular arithmetic

def solve(A, B, C, D):  # Function to solve the problem
    dp = [[0] * 3001 for _ in range(3001)]  # Initializing the dynamic programming table with zeros

    dp[A][B] = 1  # Setting the base case as dp[A][B] = 1

    for c in range(A, C + 1):  # Iterating over all possible values of c from A to C
        for d in range(B, D + 1):  # Iterating over all possible values of d from B to D
            if c == A and d == B:  # Skipping the base case as it has already been calculated
                continue

            ans = 0  # Initializing the answer as zero

            if c > A:  # If c is greater than A
                part = dp[c - 1][d]  # Calculating the sub-answer for the previous value of c and the same value of d
                ans = (part * d) % MOD  # Multiplying the sub-answer with the current value of d

            if d > B:  # If d is greater than B
                part = dp[c][d - 1]  # Calculating the sub-answer for the same value of c and the previous value of d
                ans = (ans + (part * c)) % MOD  # Adding the sub-answer multiplied by the current value of c to the answer

            if c > A and d > B:  # If both c and d are greater than their respective initial values
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))) % MOD  # Subtracting the answer for the previous values of c and d multiplied by their difference

            dp[c][d] = (ans + MOD) % MOD  # Updating the answer for the current values of c and d

    return dp[C][D]  # Returning the final answer

if __name__ == "__main__":  # Main function to run the program
    input = sys.stdin.read
    data = list(map(int, input().strip().split()))  # Reading input
    A, B, C, D = data  # Unpacking the input values
    result = solve(A, B, C, D)  # Calling the solve function to solve the problem
    print(result)  # Printing the final answer

# <END-OF-CODE>
