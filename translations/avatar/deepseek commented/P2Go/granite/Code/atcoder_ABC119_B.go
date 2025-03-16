

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())
	x := make([]float64, N)
	for i := 0; i < N; i++ {
		s := bufio.NewReader(os.Stdin).Scan()
		s = strings.Replace(s, "JPY", "* 1.0", -1)
		s = strings.Replace(s, "BTC", "* 380000.0", -1)
		x[i], _ = strconv.ParseFloat(s, 64)
	}
	fmt.Println(sum(x))
}

func sum(x []float64) float64 {
	s := 0.0
	for _, v := range x {
		s += v
	}
	return s
}

