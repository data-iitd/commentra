<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Reading Inputs
	var X, Y, Z, K int
	fmt.Scanf("%d %d %d %d\n", &X, &Y, &Z, &K)

	// Step 2: Vector Initialization and Input
	A := make([]int, X)
	B := make([]int, Y)
	C := make([]int, Z)
	for i := 0; i < X; i++ {
		fmt.Scanf("%d\n", &A[i])
	}
	for i := 0; i < Y; i++ {
		fmt.Scanf("%d\n", &B[i])
	}
	for i := 0; i < Z; i++ {
		fmt.Scanf("%d\n", &C[i])
	}

	// Step 3: Sorting
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
	sort.Slice(B, func(i, j int) bool { return B[i] > B[j] })
	sort.Slice(C, func(i, j int) bool { return C[i] > C[j] })

	// Step 4: Combining A and B
	AB := make([]int, 0)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	// Step 5: Sorting AB
	sort.Slice(AB, func(i, j int) bool { return AB[i] > AB[j] })

	// Step 6: Combining AB and C
	ABC := make([]int, 0)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	// Step 7: Sorting ABC
	sort.Slice(ABC, func(i, j int) bool { return ABC[i] > ABC[j] })

	// Step 8: Output
	for i := 0; i < K; i++ {
		fmt.Printf("%d\n", ABC[i])
	}
}

