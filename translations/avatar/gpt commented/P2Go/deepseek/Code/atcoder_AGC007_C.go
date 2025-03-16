package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read input values for N, d, and x from standard input
func readInput() (int, int, int) {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	values := strings.Split(strings.TrimSpace(input), " ")
	N, _ := strconv.Atoi(values[0])
	d, _ := strconv.Atoi(values[1])
	x, _ := strconv.Atoi(values[2])
	return N, d, x
}

func main() {
	N, d, x := readInput()
	ret := 0

	for N > 0 {
		ret += d + (float64(N)-0.5)*float64(x)
		d = d + (d / float64(N)) + (5*float64(x))/(2*float64(N))
		x += 2 * float64(x) / float64(N)
		N--
	}

	fmt.Println(ret)
}
