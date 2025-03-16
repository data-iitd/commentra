package main

import (
	"fmt"
	"math"
)

func main() {
	var R int
	fmt.Scanf("%d", &R)
	if R < 1200 {
		fmt.Println("ABC")
	} else if R >= 2800 {
		fmt.Println("AGC")
	} else {
		fmt.Println("ARC")
	}
}

Translate the above Go code to Python and end with comment "