import sys
from collections import defaultdict

class TaskD:
    def solve(self, test_number, input_stream, output_stream):
        # Read the number of elements and the modulus value
        n, m = map(int, input_stream.readline().split())
        
        # Read the array of integers
        a = list(map(int, input_stream.readline().split()))
        
        # Initialize a defaultdict to store counts of remainders
        dp = defaultdict(int)
        ans = 0  # Variable to store the final answer
        base = 0  # Variable to track the base remainder
        
        # Iterate through the array to calculate the answer
        for i in range(n):
            # Update the base remainder
            base = (base - a[i] % m + m) % m
            
            # Merge the current remainder into the defaultdict
            dp[(base + a[i]) % m] += 1
            
            # Add the count of occurrences of the current base remainder to the answer
            ans += dp[base]
        
        # Output the final answer
        output_stream.write(f"{ans}\n")

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Create an instance of TaskD to solve the problem
    solver = TaskD()
    
    # Solve the problem for the first test case
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
