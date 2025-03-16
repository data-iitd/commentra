

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N int
	fmt.Fscan(reader, &N)

	x := make([]float64, N)
	u := make([]string, N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &x[i], &u[i])
	}

	fmt.Println(solve(x, u))
}

func solve(x []float64, u []string) float64 {
	sum := 0.0
	for i := 0; i < len(x); i++ {
		factor := 1.0
		if u[i] == "JPY" {
			factor = 1.0
		} else {
			factor = 380000.0
		}
		sum += x[i] * factor
	}
	return sum
}

// END-OF-CODE