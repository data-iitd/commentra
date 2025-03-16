package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var n, num int
	fmt.Scan(&n, &num)

	numSet := make(map[int]struct{})
	var inputNum int
	for i := 0; i < n; i++ {
		fmt.Scan(&inputNum)
		numSet[inputNum] = struct{}{}
	}

	twoTimesSet := make(map[int]struct{})
	for i := range numSet {
		count := 0
		for j := 1; j < 30; j++ {
			i /= 2
			if i%2 != 0 {
				twoTimesSet[j] = struct{}{}
				count++
				break
			}
		}
		if len(twoTimesSet) != 1 {
			fmt.Println(0)
			return
		}
	}

	// Calculate the least common multiple (LCM)
	lcm := 1
	for num := range numSet {
		lcm = lcm * num / gcd(lcm, num)
	}

	// Calculate and print the final result based on the LCM and the input number
	fmt.Println((num-lcm/2)/lcm + 1)
}

// <END-OF-CODE>
