import sys

class Solution:
    def solve(self, in_stream, out_stream):
        # Read the number of elements (n) and the number of smallest elements to sum (k)
        n, k = map(int, in_stream.readline().split())
        
        # Read n integers from input and store them in a list
        a = list(map(int, in_stream.readline().split()))
        
        # Sort the list in ascending order
        a.sort()
        
        # Calculate the sum of the smallest k elements
        ans = sum(a[:k])
        
        # Output the result (sum of the smallest k elements)
        out_stream.write(f"{ans}\n")

if __name__ == "__main__":
    # Create an instance of the Solution class to solve the problem
    sol = Solution()
    
    # Call the solve method to process the input and produce output
    sol.solve(sys.stdin, sys.stdout)

# <END-OF-CODE>
