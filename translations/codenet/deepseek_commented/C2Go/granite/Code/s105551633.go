
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a type alias for int64
type int64 = int64

// Define a function to count the number of digits in a number
func digit(n int64) int {
	res := 0
	for n > 0 {
		res++
		n /= 10
	}
	return res
}

// Main logic of the program
func run() {
	var n int64
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	min := digit(n)
	for i := 1; int64(i)*i <= n; i++ {
		if n%i!= 0 {
			continue
		}
		a := int64(i)
		b := n / i
		min = int(math.Min(float64(min), math.Max(float64(digit(a)), float64(digit(b)))))
	}
	fmt.Println(min)
}

// Main function
func main() {
	run()
}

// End of code
// 