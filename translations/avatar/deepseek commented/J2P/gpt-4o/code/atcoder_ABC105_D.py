import sys
from collections import defaultdict

class TaskD:
    def solve(self, n, m, a):
        # HashMap to store the frequency of remainders
        dp = defaultdict(int)
        
        # Initialize the answer and base variable
        ans = 0
        base = 0
        
        # Iterate through the array to calculate the answer
        for i in range(n):
            # Update the base variable
            base = (base - a[i] % m + m) % m
            
            # Update the frequency of remainders in the HashMap
            dp[(base + a[i]) % m] += 1
            
            # Add the frequency of the current remainder to the answer
            ans += dp[base]
        
        # Print the final answer
        print(ans)

def main():
    # Read the number of elements and the modulo value
    n, m = map(int, sys.stdin.readline().split())
    
    # Read the array of elements
    a = list(map(int, sys.stdin.readline().split()))
    
    # Create an instance of TaskD and solve the problem
    solver = TaskD()
    solver.solve(n, m, a)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
