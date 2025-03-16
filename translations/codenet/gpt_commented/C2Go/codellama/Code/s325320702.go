
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values for l, r, and d
	var l, r, d int
	fmt.Scan(&l)
	fmt.Scan(&r)
	fmt.Scan(&d)

	// Count the multiples of d in the range [l, r]
	ans := 0
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}

	// Output the result
	fmt.Println(ans)
}

