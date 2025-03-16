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

func lcm(a, b int) int {
	return a * (b / gcd(a, b))
}

func main() {
	var n, num int
	fmt.Scan(&n, &num)

	numSet := make(map[int]struct{})
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		numSet[x] = struct{}{}
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

	// Calculate the LCM of the integers in numSet
	var lcmValue int
	for first := range numSet {
		lcmValue = first
		break
	}
	for i := range numSet {
		if i != lcmValue {
			lcmValue = lcm(lcmValue, i)
		}
	}

	// Calculate the number of integers in the range from 1 to num that are divisible by the LCM
	result := (num - lcmValue/2) / lcmValue + 1
	fmt.Println(result)
}

// <END-OF-CODE>
