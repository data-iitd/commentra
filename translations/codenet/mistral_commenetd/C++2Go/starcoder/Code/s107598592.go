
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

// Main function starts here
func main() {
	var N int
<<<<<<< HEAD
	var X, Y []int

	// Taking input of N from the user
	fmt.Scanf("%d\n", &N)

	// Declaring two vectors X and Y of size N
	X = make([]int, N)
	Y = make([]int, N)

	// Filling the vectors X and Y with user input
=======
	fmt.Scanf("%d\n", &N)
	X := make([]int, N)
	Y := make([]int, N)
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &X[i])
		Y[i] = X[i]
	}
<<<<<<< HEAD

	// Sorting the vector Y in ascending order
	sort.Ints(Y)

	// Finding the middle element of sorted vector Y
	y := Y[len(Y)/2]

	// Iterating through the vector X and printing the middle element of Y based on the condition
=======
	sort.Ints(Y)
	y := Y[N/2]
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < N; i++ {
		if X[i] < y {
			fmt.Printf("%d\n", y)
		} else {
<<<<<<< HEAD
			fmt.Printf("%d\n", Y[len(Y)/2-1])
=======
			fmt.Printf("%d\n", y-1)
>>>>>>> 98c87cb78a (data updated)
			break
		}
	}
}

