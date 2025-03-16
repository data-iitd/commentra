package main

import (
	"fmt"
)

func main() {
	var z string
	fmt.Scan(&z)
	a := len(z)

	for i := 0; i < a-1; i++ {
		if z[i] == z[i+1] {
			fmt.Println("Bad")
			return
		}
	}
	fmt.Println("Good")
}

// <END-OF-CODE>
