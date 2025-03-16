
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
	x := make([]float64, N)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scanf("%s", &s)
		s = strings.Replace(s, "JPY", "* 1.0", -1)
		s = strings.Replace(s, "BTC", "* 380000.0", -1)
		x[i], _ = strconv.ParseFloat(s, 64)
	}
	fmt.Printf("%.2f", sum(x))
}

func sum(x []float64) float64 {
	var s float64
	for _, v := range x {
		s += v
	}
	return s
}

