package main

import (
	"fmt"
	"math"
)

func main() {
	var n, num int
	fmt.Scan(&n, &num)

	var numSet []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		numSet = append(numSet, x)
	}

	twoTimesSet := make(map[int]bool)

	for _, i := range numSet {
		count := 0
		for i%2 == 0 {
			i /= 2
			count++
		}
		twoTimesSet[count] = true
		if len(twoTimesSet) > 1 {
			fmt.Println(0)
			return
		}
	}

	lcm := numSet[0]
	for _, i := range numSet[1:] {
		lcm = lcm * i / gcd(lcm, i)
	}

	count := (num - lcm/2) / lcm + 1
	fmt.Println(count)
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

