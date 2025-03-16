package main

import (
	"fmt"
	"math"
)

func main() {
	var n int64
	fmt.Scan(&n)
	sqrt := int64(math.Sqrt(float64(n)))
	answer := 0

	for i := int64(2); i <= sqrt; i++ {
		count := 0
		for n%i == 0 {
			n /= i
			count++
		}
		for j := int64(1); count-j >= 0; j++ {
			count -= j
			answer++
		}
	}

	if n > 1 {
		answer++
	}
	fmt.Println(answer)
}

// <END-OF-CODE>
