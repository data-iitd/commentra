package main

import (
	"fmt"
)

func main() {
	// Taking the number of nodes 'N' and the number of edges 'K' as input
	var N, K int
	fmt.Scan(&N, &K)

	// Initializing the list 'L' with the given number of edges
	L := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&L[i])
	}

	// Adding a special node with index -1 at the beginning of the list 'L'
	L = append([]int{-1}, L...)

	// Initializing an empty slice 'path' to store the shortest path
	path := []int{1}

	// Initializing variables 'ind' and 'count'
	ind := 0
	count := 0

	// Initializing variables 'x' and 't'
	x := 1
	t := -1

	// Initializing a boolean variable 'flag'
	flag := false

	// Creating a map 'Hash' to store the indices of nodes
	Hash := make(map[int]int)

	// Traversing through all the nodes from 0 to 'N'
	for i := 0; i <= N; i++ {
		// Getting the next edge 'ne' from the current node 'x'
		ne := L[x]

		// Checking if the current node 'ne' is already in the hash table 'Hash'
		if _, exists := Hash[ne]; exists {
			// Setting the boolean variable 'flag' to true and storing the index of the previous occurrence of the node 'ne' in 't'
			flag = true
			t = Hash[ne]
			break
		}

		// Appending the next edge 'ne' to the list 'path'
		path = append(path, ne)

		// Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
		ind++
		Hash[ne] = ind

		// Updating the current node 'x' to the next node 'ne'
		x = ne
	}

	// Checking if there is a cycle in the graph
	if flag {
		// Storing the list of nodes in the cycle 'loop'
		loop := path[t:]

		// Checking if the length of the path is less than 'K'
		if len(path) < K {
			// Printing the 'K'th node in the path
			fmt.Println(path[K])
		} else {
			// Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
			K = K - len(path)
			K = K % len(loop)

			// Printing the 'K'th node in the cycle 'loop'
			fmt.Println(loop[K])
		}
	} else {
		// If there is no cycle in the graph, then we simply print the 'K'th node in the path
		fmt.Println(path[K-1])
	}
}

// <END-OF-CODE>
