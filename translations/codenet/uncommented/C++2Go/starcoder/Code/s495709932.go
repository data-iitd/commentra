package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &A[i])
	}

	answer := 0
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			diff := int(math.Abs(float64(A[i] - A[j])))
			answer = int(math.Max(float64(answer), float64(diff)))
		}
	}
	fmt.Printf("%d\n", answer)
}

