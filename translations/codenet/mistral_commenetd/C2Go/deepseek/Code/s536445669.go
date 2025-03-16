package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	if n%k == 0 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

