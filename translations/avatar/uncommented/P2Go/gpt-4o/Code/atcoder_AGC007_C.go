package main

import (
	"fmt"
	"os"
)

func main() {
	var N, d, x int
	fmt.Fscanf(os.Stdin, "%d %d %d", &N, &d, &x)
	result := calculate(N, d, x)
	fmt.Println(result)
}

func calculate(N, d, x int) float64 {
	ret := 0.0
	for N > 0 {
		ret += float64(d) + float64(N-1)*0.5*float64(x)
		d = d + int(float64(d)/float64(N)) + (5*float64(x))/(2*float64(N))
		x += 2 * int(float64(x)/float64(N))
		N--
	}
	return ret
}

// <END-OF-CODE>
