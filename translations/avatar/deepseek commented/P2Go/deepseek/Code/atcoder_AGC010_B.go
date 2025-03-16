package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	var a []int
	var input string
	fmt.Scan(&input)
	for _, numStr := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(numStr)
		a = append(a, num)
	}

	triangularNumber := n * (n + 1) / 2
	if sum(a)%triangularNumber != 0 {
		fmt.Println("NO")
		return
	}

	k := float64(sum(a)) / float64(triangularNumber)
	a = append(a, a[0])

	if sum([]int{(k - float64(i) + float64(j)) - float64(n) * (k - float64(i) + float64(j)) / float64(n) >= 0}) != n {
		fmt.Println("NO")
		return
	}

	fmt.Println("YES")
}

func sum(a []int) int {
	s := 0
	for _, v := range a {
		s += v
	}
	return s
}
