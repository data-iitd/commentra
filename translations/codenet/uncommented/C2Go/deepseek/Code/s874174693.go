package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	sum := 0
	m := n
	for i := 0; i < 9; i++ {
		sum += n % 10
		n /= 10
	}
	if m%sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

