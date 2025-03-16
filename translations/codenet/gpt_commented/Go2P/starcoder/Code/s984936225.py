# <START-OF-CODE>

# Define a large constant value to represent infinity
INF = 1 << 62 # Using a large value for infinity, considering the maximum possible distance

# Function to read the number of vertices (N) and edges (M) from input
def read_input():
	N, M = map(int, input().split())
	return N, M

# Function to read the edges and their weights from input
def read_edges(M):
	a = [0] * M # Array to store the starting vertices of edges
	b = [0] * M # Array to store the ending vertices of edges
	c = [0] * M # Array to store the weights of edges
	for i in range(M):
		a[i], b[i], c[i] = map(int, input().split())
	return a, b, c

# Function to initialize the distance array to hold the minimum cost to reach each vertex
def initialize_distance(N):
	dist = [INF] * N # Array to store the minimum cost to reach each vertex
	dist[0] = 0 # The starting vertex (0) has a distance of 0
	return dist

# Function to relax edges N times to find the shortest paths
def relax_edges(N, M, a, b, c, dist):
	for loop in range(N):
		for i in range(M):
			# Skip if the starting vertex distance is infinity (not reachable)
			if dist[a[i]-1] == INF:
				continue
			# If a shorter path to vertex b[i] is found, update the distance
			if dist[b[i]-1] > dist[a[i]-1]+c[i]:
				dist[b[i]-1] = dist[a[i]-1] + c[i] # Update the distance to b[i]

# Function to store the minimum distance to the last vertex
def get_answer(N, dist):
	return dist[N-1] # The answer is the distance to the last vertex

# Function to check for negative cycles and update reachable vertices
def check_negative_cycles(N, M, a, b, c, dist):
	for loop in range(N):
		for i in range(M):
			# Skip if the starting vertex distance is infinity (not reachable)
			if dist[a[i]-1] == INF:
				continue
			# If a shorter path to vertex b[i] is found, update the distance and mark it as reachable
			if dist[b[i]-1] > dist[a[i]-1]+c[i]:
				dist[b[i]-1] = dist[a[i]-1] + c[i]
				navigate[b[i]-1] = True # Mark b[i] as reachable
			# If a[i] is reachable, then b[i] is also reachable
			if navigate[a[i]-1] == True:
				navigate[b[i]-1] = True

# Function to output the result based on the reachability of the last vertex
def output_result(N, dist):
	if navigate[N-1] == True:
		print("inf") # If the last vertex is reachable, print "inf" (indicating a negative cycle)
	else:
		print(-get_answer(N, dist)) # Otherwise, print the negative of the answer (since weights were negated)

# Main function
def main():
	N, M = read_input()
	a, b, c = read_edges(M)
	dist = initialize_distance(N)
	relax_edges(N, M, a, b, c, dist)
	check_negative_cycles(N, M, a, b, c, dist)
	output_result(N, dist)

# Call the main function
main()

# 