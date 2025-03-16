
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a FastReader object to read input
	sc := FastReader{}
	// Create a PrintWriter object to write output
	pw := PrintWriter{}

	// Read an integer input
	x := sc.nextInt()
	// Initialize a counter to keep track of the number of iterations
	count := 0
	// Store the initial value of x in a temporary variable
	tmp := x

	// Initialize x to 0 to start the loop
	x = 0

	// Loop until x becomes 360
	for x != 360 {
		// Increment x by tmp
		x = x + tmp
		// If x exceeds 360, adjust it by subtracting 360
		if x > 360 {
			x = x - 360
		}
		// Increment the counter
		count++
	}

	// Print the final count
	fmt.Println(count)
}

type FastReader struct{}

func (this *FastReader) next() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func (this *FastReader) nextInt() int {
	return int(this.nextInt64())
}

func (this *FastReader) nextInt64() int64 {
	return int64(this.nextInt64())
}

func (this *FastReader) nextFloat() float64 {
	return float64(this.nextFloat64())
}

func (this *FastReader) nextFloat64() float64 {
	return float64(this.nextFloat64())
}

func (this *FastReader) nextString() string {
	return this.next()
}

type PrintWriter struct{}

func (this *PrintWriter) print(a ...interface{}) {
	fmt.Print(a...)
}

func (this *PrintWriter) println(a ...interface{}) {
	fmt.Println(a...)
}

func (this *PrintWriter) printf(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

func (this *PrintWriter) close() {}

