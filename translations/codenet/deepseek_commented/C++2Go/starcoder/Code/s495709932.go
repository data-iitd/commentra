<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
<<<<<<< HEAD
	"os"
	"sort"
	"strconv"
	"strings"
=======
>>>>>>> 98c87cb78a (data updated)
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
<<<<<<< HEAD
	A := make([]int, N)
=======
	A := make([]int64, N)
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}

<<<<<<< HEAD
	answer := 0
	// Calculate the maximum absolute difference between any two elements in the array
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			diff := int(math.Abs(float64(A[i] - A[j])))
			answer = int(math.Max(float64(answer), float64(diff)))
		}
	}
	// Output the result
	fmt.Printf("%d\n", answer)
=======
	var answer int64 = 0
	// Calculate the maximum absolute difference between any two elements in the array
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			diff := int64(math.Abs(float64(A[i] - A[j])))
			answer = int64(math.Max(float64(answer), float64(diff)))
		}
	}
	// Output the result
	fmt.Println(answer)
>>>>>>> 98c87cb78a (data updated)
}

