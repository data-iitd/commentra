package main

import (
	"fmt"
)

func main() {
	var x, a int
	fmt.Scanf("%d %d", &x, &a)
	fmt.Println((boolToInt(x >= a)) * 10)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

// <END-OF-CODE>
