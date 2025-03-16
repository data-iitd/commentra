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
	for _, v := range input.Split(" ") {
		num, _ := strconv.Atoi(v)
		a = append(a, num)
	}

	// Check if the sum of the elements in the list is divisible by the formula
	sum := 0
	for _, v := range a {
		sum += v
	}
	if sum % (n * (n + 1) / 2) != 0 {
		fmt.Println("NO")
		return
	}

	// Calculate the average of the elements in the list
	k := float64(sum) / float64(n * (n + 1) / 2)

	// Add the first element to the end of the list for simplification
	a = append(a, a[0])

	// Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
	valid := true
	for i := 1; i < len(a); i++ {
		diff := k - float64(a[i-1]) + float64(a[i])
		if diff % float64(n) != 0 && diff / float64(n) < 0 {
			valid = false
			break
		}
	}

	if valid {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
