// Importing necessary packages
import sys

// Global variables initialization
mod = 1000000007
INF = 1000000007

def main():
    # Reading input from standard input
    r = sys.stdin.readline
    # Variables initialization
    n, m, R = map(int, r().split()) # Reading number of cities n, number of roads m, and number of starting points R

    # Initializing rs slice with starting points
    rs = [int(i) - 1 for i in r().split()]

    # Initializing costs matrix with infinite values
    costs = [[INF for _ in range(n)] for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0 # Initializing costs[i][i] with zero value

    # Reading roads and filling costs matrix with their costs
    for _ in range(m):
        a, b, c = map(int, r().split()) # Reading road starting point a, road ending point b, and road cost c
        a -= 1 # Decreasing starting point index for matrix indexing
        b -= 1 # Decreasing ending point index for matrix indexing
        costs[a][b] = c # Filling costs[a][b] with cost c
        costs[b][a] = c # Filling costs[b][a] with cost c

    # Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]) # Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]

    # Calculating minimum cost of visiting all cities in a single tour
    perms = permutations(rs) # Generating all permutations of starting points
    ans = INF # Initializing answer with infinite value
    for perm in perms: # Iterating through all permutations
        tmp = 0 # Initializing temporary variable tmp with zero value
        for j in range(1, len(perm)): # Iterating through all pairs of consecutive starting points
            from = perm[j-1] # Getting previous starting point
            to = perm[j] # Getting current starting point
            tmp += costs[from][to] # Adding cost of road from from to to tmp
        ans = min(ans, tmp) # Updating answer with minimum of current answer and tmp
    print(ans) # Printing answer

# Helper function to generate all permutations of given slice
def permutations(arr):
    # Helper function initialization
    def helper(arr, n):
        if n == 1: # Base case: when only one element left in arr
            return [arr[:]] # Returning arr
        res = [] # Initializing result with empty list
        for i in range(n): # Iterating through all elements of arr
            res += [x + [arr[i]] for x in helper(arr, n-1)] # Recursively calling helper function with n-1 and adding current element to result
        if n % 2 == 1: # Swapping first and last elements when n is odd
            res[0][0], res[0][-1] = res[0][-1], res[0][0]
        else: # Swapping first and last elements when n is even
            res[0][0], res[0][-1] = res[0][-1], res[0][0]
        return res # Returning result
    return helper(arr, len(arr)) # Calling helper function with arr and its length

