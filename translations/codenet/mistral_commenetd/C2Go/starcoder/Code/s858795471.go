
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Function to search for a key in an array
func search(A []int, n int, key int) bool {
	A[n] = key
	i := 0
	// Search for the key in the array using a while loop
	for A[i]!= key {
		i++
	}
	// Return 1 if the key was found before the end of the array, otherwise return 0
	return i!= n
}

func main() {
	var n, q, key, sum int
	var A []int
	// Read the number of elements in the array from the user
	fmt.Scanf("%d", &n)
	// Read the elements of the array from the user
	A = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}
	// Read the number of queries from the user
	fmt.Scanf("%d", &q)
	// For each query, search for the key in the array and if it is found, increment the sum
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &key) // Read the key to be searched for
		// Call the search function to find the key in the array
		if search(A, n, key) {
			sum++ // If the key is found, increment the sum
		}
	}
	// Print the number of keys found
	fmt.Printf("%d\n", sum)
}

