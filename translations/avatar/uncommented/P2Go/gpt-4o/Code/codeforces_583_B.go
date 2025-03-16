package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	
	var a []int
	var input string
	fmt.Scan(&input)
	for _, s := range strings.Split(input, " ") {
		var num int
		fmt.Sscan(s, &num)
		a = append(a, num)
	}

	currentLevel := 0
	counter := 0
	counterTurns := -1

	for counter < len(a) {
		counterTurns++
		for i := 0; i < len(a); i++ {
			if a[i] != -1 && a[i] <= counter {
				counter++
				a[i] = -1
			}
		}
		reverse(a)
	}
	fmt.Println(counterTurns)
}

func reverse(a []int) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

// <END-OF-CODE>
