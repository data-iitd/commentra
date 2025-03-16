
import sys 
import math 

def solve(testNumber, in, out): 
    # Read the number of elements and the modulus value
    n, m = map(int, in.readline().split()) 
    
    # Read the array of integers
    a = list(map(int, in.readline().split())) 
    
    # Initialize a dictionary to store counts of remainders
    dp = {} 
    ans = 0 # Variable to store the final answer
    base = 0 # Variable to track the base remainder
    
    # Iterate through the array to calculate the answer
    for i in range(n): 
        # Update the base remainder
        base = (base - a[i] % m + m) % m 
        
        # Merge the current remainder into the dictionary
        dp[base + a[i]] = dp.get(base + a[i], 0) + 1 
        
        # Add the count of occurrences of the current base remainder to the answer
        ans += dp.get(base, 0) 
    
    # Output the final answer
    out.write(str(ans) + "\n") 

if __name__ == "__main__": 
    # Set up input and output streams
    in = sys.stdin 
    out = sys.stdout 
    
    # Create an instance of TaskD to solve the problem
    solver = TaskD() 
    
    # Solve the problem for the first test case
    solver.solve(1, in, out) 
    
    # Close the output stream
    out.close() 

# 