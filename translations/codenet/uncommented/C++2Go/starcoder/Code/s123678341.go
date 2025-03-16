package main
import (
	"fmt"
	"sort"
)

func main() {
	var X, Y, Z, K int
	fmt.Scanf("%d %d %d %d", &X, &Y, &Z, &K)
	A := make([]int, X)
	B := make([]int, Y)
	C := make([]int, Z)
	for i := 0; i < X; i++ {
		fmt.Scanf("%d", &A[i])
	}
	for i := 0; i < Y; i++ {
		fmt.Scanf("%d", &B[i])
	}
	for i := 0; i < Z; i++ {
		fmt.Scanf("%d", &C[i])
	}
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
	sort.Slice(B, func(i, j int) bool { return B[i] > B[j] })
	sort.Slice(C, func(i, j int) bool { return C[i] > C[j] })
	AB := make([]int, 0)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}
	sort.Slice(AB, func(i, j int) bool { return AB[i] > AB[j] })
	ABC := make([]int, 0)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}
	sort.Slice(ABC, func(i, j int) bool { return ABC[i] > ABC[j] })
	for i := 0; i < K; i++ {
		fmt.Println(ABC[i])
	}
}

