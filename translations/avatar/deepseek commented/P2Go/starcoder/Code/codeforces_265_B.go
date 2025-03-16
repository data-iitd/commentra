package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var l []int
	var ans int
	var last int

	// Read the number of elements in the list
	fmt.Scanf("%d", &n)

	// Read n elements and append them to the list l
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		l = append(l, x)
	}

	ans = n - 1
	last = 0

	// Iterate over each element in the list l
	for _, i := range l {
		ans += abs(last - i) + 1
		last = i
	}

	fmt.Printf("%d\n", ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

