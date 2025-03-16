
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Function to perform linear search on an array
func linearsearch(S []int, n int, key int) int {
	i := 0
	count := 0

	// Search for the key in the array S until it is found or the end of the array is reached
	for S[i]!= key {
		i++
		if i >= n {
			count = 1
			return count
		}
	}

	// If key is found, return 0 to indicate that it was found
	return 0
}

// Main function to read input and call linearsearch function
func main() {
	var i, j, n, q, S [10000]int
	var T [10000]int
	var count int

	// Read the size of the array S from the user
	fmt.Println("Enter the size of the array S: ")
	fmt.Scanf("%d", &n)

	// Read the elements of array S from the user
	fmt.Println("Enter", n, "integers for array S:")
	for i = 0; i < n; i++ {
		fmt.Println("Enter integer S[", i, "]: ")
		fmt.Scanf("%d", &S[i])
	}

	// Read the number of queries from the user
	fmt.Println("Enter the number of queries: ")
	fmt.Scanf("%d", &q)

	// Read the elements of array T from the user
	fmt.Println("Enter", q, "integers for array T:")
	for j = 0; j < q; j++ {
		fmt.Println("Enter integer T[", j, "]: ")
		fmt.Scanf("%d", &T[j])
	}

	// Call linearsearch function for each element of array T and increment count if key is not found
	for j = 0; j < q; j++ {
		key := T[j]
		if linearsearch(S, n, key) == 1 {
			count++
		}
	}

	// Print the final count to the user
	fmt.Println("Number of integers in array S that are not present in array T:", count)
}

