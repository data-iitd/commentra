package main

import (
	"fmt"
)

func main() {
	var K int
	fmt.Scan(&K)
	var S string
	fmt.Scan(&S)

	if len(S) <= K {
		fmt.Println(S)
		return
	}
	fmt.Println(S[:K] + "...")
}

// <END-OF-CODE>
