package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	var n, num int
	fmt.Scan(&n, &num)

	var numSet []int
	numSetMap := make(map[int]bool)
	var numStr string
	fmt.Scan(&numStr)
	for _, num := range numStr {
		numSetMap[int(num-'0')] = true
	}

	twoTimesSet := make(map[int]bool)

	for i := range numSetMap {
		count := 0
		for i%2 == 0 {
			i /= 2
			count++
		}
		if count > 0 {
			twoTimesSet[count] = true
		}
	}

	if len(twoTimesSet) != 1 {
		fmt.Println(0)
		return
	}

	numSet = make([]int, 0, len(numSetMap))
	for i := range numSetMap {
		numSet = append(numSet, i)
	}

	lcm := numSet[0]
	for _, i := range numSet[1:] {
		lcm = lcm * i / gcd(lcm, i)
	}

	result := (num - lcm/2) / lcm + 1
	fmt.Println(result)
}
