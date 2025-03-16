package main

import (
	"fmt"
	"math"
)

func main() {
	var n int64
	fmt.Scan(&n)
	sqrt := int(math.Sqrt(float64(n)))
	answer := 0
	for i := 2; i <= sqrt; i++ {
		count := 0
		for n%int64(i) == 0 {
			n /= int64(i)
			count++
		}
		for j := 1; count-j >= 0; j++ {
			count -= j
			answer++
		}
	}
	if n > 1 {
		answer++
	}
	fmt.Println(answer)
}

