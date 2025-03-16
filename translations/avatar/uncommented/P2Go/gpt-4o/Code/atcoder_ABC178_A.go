package main

import (
	"fmt"
)

func solve() {
	var a int
	fmt.Scan(&a)
	if a == 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}

func main() {
	tcs := 1
	for tc := 1; tc <= tcs; tc++ {
		solve()
	}
}

// <END-OF-CODE>
