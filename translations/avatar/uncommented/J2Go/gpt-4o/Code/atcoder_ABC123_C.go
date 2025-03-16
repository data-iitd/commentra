package main

import (
	"fmt"
	"math"
)

func main() {
	var N int64
	fmt.Scan(&N)

	var min int64
	for i := 0; i < 5; i++ {
		var num int64
		fmt.Scan(&num)
		if i == 0 {
			min = num
		} else {
			if num < min {
				min = num
			}
		}
	}

	result := int64(math.Ceil(float64(N) / float64(min))) + 4
	fmt.Println(result)
}

// <END-OF-CODE>
