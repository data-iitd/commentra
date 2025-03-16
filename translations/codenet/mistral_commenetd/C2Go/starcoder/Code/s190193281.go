
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n, q int
	var S []int
	var T []int
	var c int

	// Read the size of the array
	fmt.Print("Enter the size of the array: ")
	fmt.Scanf("%d\n", &n)

	// Allocate memory for the array
	S = make([]int, n)

	// Read the elements of the array
	fmt.Print("Enter ", n, " integers:\n")
	for i := 0; i < n; i++ {
		fmt.Print("Element ", i+1, ": ")
		fmt.Scanf("%d\n", &S[i])
	}

	// Read the number of queries
	fmt.Print("Enter the number of queries: ")
	fmt.Scanf("%d\n", &q)

	// Allocate memory for the queries
	T = make([]int, q)

	// Read the queries
	fmt.Print("Enter ", q, " integers to be searched:\n")
	for i := 0; i < q; i++ {
		fmt.Print("Query ", i+1, ": ")
		fmt.Scanf("%d\n", &T[i])

		// Check if the query is present in the array
		if sort.SearchInts(S, T[i])!= -1 {
			c++
		}
	}

	// Print the number of queries present in the array
	fmt.Print("Number of queries present in the array: ", c, "\n")
}

