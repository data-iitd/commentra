
import sys; // Importing sys for input and output

MOD = 998244353; // Modulus value for modular arithmetic

dp = [[0 for i in range(3001)] for j in range(3001)]; // 2D dynamic programming table for storing intermediate results

def solve(A, B, C, D): # Function to solve the problem

  dp[A][B] = 1; # Setting the base case as dp[A][B] = 1

  for c in range(A, C + 1): # Iterating over all possible values of c from A to C
    for d in range(B, D + 1): # Iterating over all possible values of d from B to D
      if c == A and d == B: # Skipping the base case as it has already been calculated
        continue;

      ans = 0; # Initializing the answer as zero

      if c > A: # If c is greater than A
        part = dp[c - 1][d]; # Calculating the sub-answer for the previous value of c and the same value of d
        ans = (part * d); # Multiplying the sub-answer with the current value of d
      if d > B: # If d is greater than B
        part = dp[c][d - 1]; # Calculating the sub-answer for the same value of c and the previous value of d
        ans = (ans + (part * c)); # Adding the sub-answer multiplied by the current value of c to the answer
      if c > A and d > B: # If both c and d are greater than their respective initial values
        ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); # Subtracting the answer for the previous values of c and d multiplied by their difference

      dp[c][d] = (ans % MOD + MOD) % MOD; # Updating the answer for the current values of c and d

  return dp[C][D]; # Returning the final answer

if __name__ == "__main__": # Main function to run the program
  A = int(sys.stdin.readline().strip()); # Reading the first number A from input
  B = int(sys.stdin.readline().strip()); # Reading the second number B from input
  C = int(sys.stdin.readline().strip()); # Reading the third number C from input
  D = int(sys.stdin.readline().strip()); # Reading the fourth number D from input
  print(solve(A, B, C, D)); # Printing the final answer

