
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Ask the user for the number of inputs
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Create a list 'x' of size 'N' using a list comprehension
	x := make([]float64, N)
	for i := 0; i < N; i++ {
		s := bufio.NewReader(os.Stdin).Scan()
		s = strings.Replace(s, "JPY", "* 1.0", -1)
		s = strings.Replace(s, "BTC", "* 380000.0", -1)
		x[i], _ = strconv.ParseFloat(s, 64)
	}

	// Print the sum of all the elements in the list 'x'
	fmt.Println(sum(x))
}

func sum(x []float64) float64 {
	s := 0.0
	for _, v := range x {
		s += v
	}
	return s
}

