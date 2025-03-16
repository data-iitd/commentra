import sys

class Fast:
    def sol(self, s, queries):
        # Initialize a cumulative array to count consecutive characters
        cum = [0] * (len(s) + 1)
        cum[0] = cum[-1] = 0
        
        # Fill the cumulative array with counts of consecutive characters
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]
        
        # Process each query
        results = []
        for l, r in queries:
            results.append(cum[r - 1] - cum[l - 1])
        
        return results

# Read input from stdin
s = sys.stdin.readline().strip()
q = int(sys.stdin.readline().strip())
queries = [tuple(map(int, sys.stdin.readline().strip().split())) for _ in range(q)]

# Create an instance of the Fast class and call the solution method
f = Fast()
results = f.sol(s, queries)

# Print the results
for result in results:
    print(result)
