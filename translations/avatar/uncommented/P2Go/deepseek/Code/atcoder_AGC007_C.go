package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	read, _ := reader.ReadBytes('\n')
	var N, d, x int
	fmt.Sscanf(string(read), "%d %d %d", &N, &d, &x)

	ret := 0
	for N > 0 {
		ret += d + (float64(N-1)*float64(x))
		d = d + (d/float64(N)) + (5*float64(x))/(2*float64(N))
		x += 2 * float64(x) / float64(N)
		N--
	}
	fmt.Println(ret)
}
