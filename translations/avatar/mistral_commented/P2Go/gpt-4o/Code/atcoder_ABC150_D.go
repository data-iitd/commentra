package main

import (
	"fmt"
	"math"
	"os"
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
		powerOfTwo := 0
		for i%2 == 0 {
			powerOfTwo++
			i /= 2
		}

		if powerOfTwo > 1 {
			fmt.Println(0)
			return
		}

		twoTimesSet[powerOfTwo] = struct{}{}
	}

	if len(twoTimesSet) != 1 {
		fmt.Println(0)
		return
	}

	numList := make([]int, 0, len(numSet))
	for k := range numSet {
		numList = append(numList, k)
	}

	lcmValue := numList[0]
	for i := 1; i < len(numList); i++ {
		lcmValue = lcm(lcmValue, numList[i])
	}

	fmt.Println((num - lcmValue/2) / lcmValue + 1)
}

// <END-OF-CODE>
