
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int64
	fmt.Scan(&N)

	min := int64(0)
	for i := 0; i < 5; i++ {
		if i == 0 {
			min = int64(0)
		}
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

	fmt.Println(int64(math.Ceil(float64(N)/float64(min))) + 4)
}

