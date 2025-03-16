
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}
	gcd := A[0]
	for i := 1; i < N; i++ {
		gcd = gcdGCD(gcd, A[i])
	}
	fmt.Println(gcd)
}

func gcdGCD(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

