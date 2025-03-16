package main

import (
	"fmt"
	"math"
	"sort"
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
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		numSet[x] = struct{}{}
	}

	twoTimesSet := make(map[int]struct{})
	for i := range numSet {
		for j := 1; j < 30; j++ {
			i /= 2
			if i%2 != 0 {
				twoTimesSet[j] = struct{}{}
				break
			}
		}
		if len(twoTimesSet) != 1 {
			fmt.Println(0)
			return
		}
	}

	numList := make([]int, 0, len(numSet))
	for k := range numSet {
		numList = append(numList, k)
	}

	sort.Ints(numList)
	lcm := numList[0]
	for i := 1; i < len(numList); i++ {
		lcm = lcm * numList[i] / gcd(lcm, numList[i])
	}

	fmt.Println((num - lcm/2) / lcm + 1)
}

// <END-OF-CODE>
