package main

import (
	"fmt"
	"os"
)

func main() {
	var n int
	_, err := fmt.Scan(&n)
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}
	solve(n)
}

func solve(n int) {
	result := (n / 3) * 2
	if n%3 != 0 {
		result++
	}
	fmt.Println(result)
}

// <END-OF-CODE>
