import sys

# Constants for the modulo operation and infinity value
mod = 1000000007
INF = 1000000007

def main():
	# Read the number of cities, roads, and restaurants
	n, m, R = map(int, input().split())

	# Read the indices of the restaurants and decrement by 1 for 0-based indexing
	rs = list(map(int, input().split()))
	for i in range(len(rs)):
		rs[i] -= 1

	# Initialize the cost matrix with INF and set diagonal to 0
	costs = [[INF for i in range(n)] for j in range(n)]
	for i in range(n):
		costs[i][i] = 0

	# Read the road connections and their costs, updating the cost matrix
	for i in range(m):
		a, b, c = map(int, input().split())
		a -= 1
		b -= 1
		costs[a][b] = c
		costs[b][a] = c

	# Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
	for k in range(n):
		for i in range(n):
			for j in range(n):
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j])

	# Generate all permutations of the restaurant indices and find the minimum cost tour
	perms = permutations(rs)
	ans = INF
	for perm in perms:
		tmp = 0
		for j in range(1, len(perm)):
			from_ = perm[j-1]
			to = perm[j]
			tmp += costs[from_][to]
		ans = min(ans, tmp)
	print(ans)

# Function to generate all permutations of a given array
def permutations(arr):
	if len(arr) == 1:
		return [arr]
	res = []
	for i in range(len(arr)):
		tmp = arr[i]
		arr[i] = arr[-1]
		arr[-1] = tmp
		res += [[tmp] + sub for sub in permutations(arr[:-1])]
		if len(arr)%2 == 1:
			tmp = arr[i]
			arr[i] = arr[0]
			arr[0] = tmp
		else:
			tmp = arr[0]
			arr[0] = arr[i]
			arr[i] = tmp
	return res

if __name__ == "__main__":
	main()

