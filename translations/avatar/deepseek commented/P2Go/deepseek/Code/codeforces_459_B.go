package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	var l1 []int
	var input string
	fmt.Scan(&input)

	for _, numStr := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(numStr)
		l1 = append(l1, num)
	}

	sort.Ints(l1)

	a := l1[len(l1)-1]
	b := l1[0]

	if a == b {
		fmt.Println(a - b, n*(n-1)/2)
	} else {
		ac := 0
		bc := 0
		for _, num := range l1 {
			if num == a {
				ac++
			}
			if num == b {
				bc++
			}
		}
		fmt.Println(a - b, ac*bc)
	}
}
