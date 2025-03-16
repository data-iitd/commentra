
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define magic 1000000007

// Function to check if a number exists in the array p
int find(int n, int p[], int N) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0; // Number found
		}
	}
	return 1; // Number not found
}

// Main solving function
void solve() {
	int X, N;
	int p[200000];

	// PARSE HELPER SESSION
	// Read and log the input values
	scanf("%d", &X); // Read an integer
	printf("%d\n", X); // Log the integer
	scanf("%d", &N); // Read the size of the array
	printf("%d\n", N); // Log the size
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]); // Read integers into the array p
	}
	printf("p %d\n", p[0]); // Log the first element of p

	// Check for numbers around X that are not in the array p
	for (int i = 0; i <= 100; i++) {
		if (find(X - i, p, N) == 1) { // Check X - i
			printf("%d\n", X - i); // Print the result
			exit(0); // Exit the program
		}
		if (find(X + i, p, N) == 1) { // Check X + i
			printf("%d\n", X + i); // Print the result
			exit(0); // Exit the program
		}
	}

	// OUTPUT GENERATION PART
	// ans := 0
	// printf("%d\n", ans);

	// if (ans > 0) {
	//   printf("Yes\n");
	// } else {
	//   printf("No\n");
	// }

	// BFS/DFS PART
	// visited := []int{}
	// bfs/dfs(1, neighbor, func(node int) {
	// 	visited = append(visited, node)
	// })
	// printf("%v\n", visited)

	// DFS 2
	// var dp [2000000]int
	// nei := make(map[int][]int)
	// nei[0] = []int{1, 2}
	// nei[1] = []int{0}
	// nei[2] = []int{0, 3}
	// nei[3] = []int{2}
	// dfs2(0, nei, func(n, p int) {
	// 	printf("%v -> %v\n", p, n)
	// 	dp[n] = p
	// }, func(n, p int) {
	// 	printf("%v -> %v\n", n, p)
	// })
	// printf("%v\n", dp[0:5])

	// COMBINATION
	// printf("%d %d %d\n", N, M, intMax(N, M))
	// printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M))
}

// Main function to execute the program
int main() {
	solve(); // Call the solve function
	return 0;
}

