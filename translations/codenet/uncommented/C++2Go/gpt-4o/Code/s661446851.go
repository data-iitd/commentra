package main

import (
	"fmt"
)

func solve() {
	var n int
	fmt.Scan(&n)
	fmt.Println(n == 0)
}

func main() {
	n := 1 // Uncomment the next line to read from input: fmt.Scan(&n)
	for n > 0 {
		solve()
		n--
	}
}

// <END-OF-CODE>
