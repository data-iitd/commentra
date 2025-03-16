<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Function to find the smallest divisor of a number
func div(n int) int {
	if n%2 == 0 {
		return 2
	}
	s := int(math.Sqrt(float64(n)))
	for i := 3; i <= s; i += 2 {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main() {
	var num int
	fmt.Scanf("%d", &num)
	fmt.Printf("%d:", num)
	for num!= 1 {
		fmt.Printf(" %d", div(num))
		num = num / div(num)
	}
	fmt.Println()
}

