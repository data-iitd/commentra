package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	x := make([]float64, N)
	u := make([]string, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		x[i], _ = strconv.ParseFloat(scanner.Text(), 64)
		scanner.Scan()
		u[i] = scanner.Text()
	}
	fmt.Println(solve(x, u))
}

func solve(x []float64, u []string) float64 {
	var sum float64
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			sum += x[i]
		} else {
			sum += x[i] * 380000
		}
	}
	return sum
}

