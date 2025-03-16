package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x)
	boolValue := x == 1
	result := 0
	if !boolValue {
		result = 1
	}
	fmt.Println(result)
}

// <END-OF-CODE>
