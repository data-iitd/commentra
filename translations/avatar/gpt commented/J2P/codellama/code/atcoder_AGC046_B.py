import sys 

# Define a constant for the modulo operation
MOD = 998244353 
# Create a 2D array for dynamic programming
dp = [[0] * 3001 for _ in range(3001)] 

# Method to solve the problem
def solve(sc, pw): 
    # Read input values A, B, C, D from the scanner
    A, B, C, D = map(int, sc.readline().split()) 
    
    # Initialize the starting point in the dp array
    dp[A][B] = 1 
    
    # Iterate over the range from A to C and B to D
    for c in range(A, C + 1): 
        for d in range(B, D + 1): 
            # Skip the initial point
            if c == A and d == B: 
                continue 
            
            # Variable to store the current answer
            ans = 0 
            
            # If moving down (increasing c)
            if c > A: 
                part = dp[c - 1][d] 
                ans = (part * d) % MOD # Calculate contribution from the previous row
            
            # If moving right (increasing d)
            if d > B: 
                part = dp[c][d - 1] 
                ans = (ans + (part * c)) % MOD # Calculate contribution from the previous column
            
            # If moving diagonally (increasing both c and d)
            if c > A and d > B: 
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))) % MOD # Adjust for double counting
            
            # Store the result in the dp array with modulo adjustment
            dp[c][d] = (ans + MOD) % MOD 
    
    # Output the final result for dp[C][D]
    pw.write(str(dp[C][D]) + '\n') 

# Main method to execute the program
if __name__ == '__main__': 
    sc = sys.stdin 
    pw = sys.stdout 
    solve(sc, pw) 
    pw.flush() 
    pw.close() 
    sc.close() 

