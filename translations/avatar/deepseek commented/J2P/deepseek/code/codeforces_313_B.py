import sys

class Fast:
    def sol(self, s, queries):
        # Initialize the cumulative array to store counts of consecutive identical characters
        cum = [0] * (len(s) + 1)
        
        # Fill the cumulative array with counts of consecutive identical characters
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]
        
        # Process each query
        results = []
        for l, r in queries:
            # Calculate and store the result for the query
            results.append(cum[r - 1] - cum[l - 1])
        
        # Print the results
        for result in results:
            print(result)

# Read input
s = input().strip()
q = int(input().strip())
queries = [tuple(map(int, input().strip().split())) for _ in range(q)]

# Create an instance of Fast and call the sol method
f = Fast()
f.sol(s, queries)
