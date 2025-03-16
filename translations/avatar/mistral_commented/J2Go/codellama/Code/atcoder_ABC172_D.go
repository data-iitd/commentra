package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var ans int64

	// We read an integer n from the standard input stream using the fmt.Scanln function
	fmt.Scanln(&n)

	for i := 1; i < n+1; i++ {
		ans += int64(i) * int64(n/i) * (int64(n/i) + 1) / 2
	}

	fmt.Println(ans)

	os.Exit(0)
}

