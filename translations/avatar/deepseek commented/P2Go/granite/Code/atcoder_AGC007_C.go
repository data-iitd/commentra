
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	read  = bufio.NewReader(os.Stdin)
	readline = func() string {
		line, _, _ := read.ReadLine()
		return string(line)
	}()
	readlines = func() []string {
		var lines []string
		for line, _, _ := read.ReadLine(); line!= nil; line, _, _ = read.ReadLine() {
			lines = append(lines, string(line))
		}
		return lines
	}()
)

func main() {
	// Reading the values of N, d, and x from standard input
	N, d, x := mustParseInt32s(readline())

	// Defining the main function to calculate a result based on N, d, and x
	ret := int64(0) // Initializing the result variable to accumulate the result
	for N > 0 {      // Running the loop while N is greater than 0
		// Incrementing ret by the sum of d and (N - 0.5) * x
		ret += int64(d) + int64((N-0.5)*x)

		// Updating the value of d using a complex formula
		d += int(d/N) + int((5*x)/(2*N))

		// Updating the value of x using another formula
		x += 2 * x / N

		// Decrementing N by 1
		N--
	}

	// Printing the result of the main function
	fmt.Println(ret)
}

func mustParseInt32s(s string) (int32, int32, int32) {
	var a, b, c int32
	n, _ := fmt.Sscanf(s, "%d %d %d", &a, &b, &c)
	if n!= 3 {
		panic("invalid input")
	}
	return a, b, c
}

