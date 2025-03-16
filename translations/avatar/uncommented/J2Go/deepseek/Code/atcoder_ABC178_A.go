package main

import (
	"fmt"
	"os"
)

func main() {
	var x int
	fmt.Scan(&x)

	bool := x == 1
	result := 0
	if !bool {
		result = 1
	}

	os.Stdout.Write([]byte(fmt.Sprintf("%d\n", result)))
}

