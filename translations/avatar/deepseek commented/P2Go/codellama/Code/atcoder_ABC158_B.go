package main

import (
	"fmt"
	"math"
)

func main() {
	var N, A, B int
	fmt.Scan(&N, &A, &B)
	mod := int(math.Pow(10, 9) + 7)
	ans := 0
	rep := N / (A + B)
	ans += rep * A
	res := N - rep*(A+B)
	ans += int(math.Min(float64(res), float64(A)))
	fmt.Println(ans)
}

