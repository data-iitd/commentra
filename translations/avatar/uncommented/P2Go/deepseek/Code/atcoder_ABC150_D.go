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
	for _, v := range fmt.Scan(&numSet) {
		numSetMap[v] = true
	}

	twoTimesSet := make(map[int]bool)
	for i := range numSetMap {
		for j := 1; j <= 30; j++ {
			i /= 2
			if i%2 != 0 {
				twoTimesSet[j] = true
				break
			}
		}
		if len(twoTimesSet) != 1 {
			fmt.Println(0)
			return
		}
	}

	numList := []int{}
	for i := range numSetMap {
		numList = append(numList, i)
	}

	lcm := numList[0]
	for i := 1; i < len(numList); i++ {
		lcm = lcm * numList[i] / gcd(lcm, numList[i])
	}

	result := (num - lcm/2) / lcm + 1
	fmt.Println(result)
}
