

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers `a` and `b` from the standard input
	reader := bufio.NewReader(os.Stdin)
	aStr, _ := reader.ReadString('\n')
	bStr, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(strings.TrimSpace(aStr))
	b, _ := strconv.Atoi(strings.TrimSpace(bStr))

	// Convert the integer `b` to a string `bstr` using the `FormatInt()` function
	bstr := strconv.FormatInt(int64(b), 10)

	// Calculate the number `num` as the product of `a` and `10` raised to the power of the length of the string `bstr`, plus the integer `b`
	num := a * int(math.Pow(10, float64(len(bstr)))) + b

	// Initialize a loop counter `i`
	i := 1

	// Enter a `for` loop that runs from `1` to `100100`
	for i <= 100100 {
		// Inside the loop, check if the square of `i` is equal to the number `num`
		if i*i == num {
			// If it is, break out of the loop
			break
		}
		// Increment the loop counter `i` by `1`
		i++
	}

	// If the loop completes without finding a square root of `num`, print "No" to the standard output
	if i > 100100 {
		fmt.Println("No")
	}
	// If we find a square root of `num` inside the loop, print "Yes" to the standard output
	else {
		fmt.Println("Yes")
	}
}

