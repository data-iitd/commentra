package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	N, _ := strconv.Atoi(sc.Text())
	x := make([]float64, N)
	u := make([]string, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.ParseFloat(sc.Text(), 64)
		u[i] = sc.Text()
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

