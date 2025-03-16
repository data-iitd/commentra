package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements and the list of integers from input
	var n int
	var a []int
	fmt.Scan(&n)
	fmt.Scan(&a)
	a = strings.Split(a, " ")
	for i := 0; i < len(a); i++ {
		a[i], _ = strconv.Atoi(a[i])
	}

	// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
	if sum(a) % (n * (n + 1) / 2) {
		// If not divisible, print "NO" and exit
		fmt.Println("NO")
		return
	}

	// Calculate the average value 'k' that each element should contribute
	k := sum(a) / (n * (n + 1) / 2)

	// Append the first element of 'a' to the end of the list to facilitate circular calculations
	a = append(a, a[0])

	// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
	if sum([(k - i + j) % n for i, j in zip(a[1:], a)]) || sum([(k - i + j) / n >= 0 for i, j in zip(a[1:], a)]) != n {
		// If either condition fails, print "NO"
		fmt.Println("NO")
	} else {
		// If both conditions are satisfied, print "YES"
		fmt.Println("YES")
	}
}

func sum(a []int) int {
	var s int
	for i := 0; i < len(a); i++ {
		s += a[i]
	}
	return s
}

func zip(a, b []int) [][]int {
	var c [][]int
	for i := 0; i < len(a); i++ {
		c = append(c, []int{a[i], b[i]})
	}
	return c
}

func main() {
	// Read the number of elements and the list of integers from input
	var n int
	var a []int
	fmt.Scan(&n)
	fmt.Scan(&a)
	a = strings.Split(a, " ")
	for i := 0; i < len(a); i++ {
		a[i], _ = strconv.Atoi(a[i])
	}

	// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
	if sum(a) % (n * (n + 1) / 2) {
		// If not divisible, print "NO" and exit
		fmt.Println("NO")
		return
	}

	// Calculate the average value 'k' that each element should contribute
	k := sum(a) / (n * (n + 1) / 2)

	// Append the first element of 'a' to the end of the list to facilitate circular calculations
	a = append(a, a[0])

	// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
	if sum([(k - i + j) % n for i, j in zip(a[1:], a)]) || sum([(k - i + j) / n >= 0 for i, j in zip(a[1:], a)]) != n {
		// If either condition fails, print "NO"
		fmt.Println("NO")
	} else {
		// If both conditions are satisfied, print "YES"
		fmt.Println("YES")
	}
}

func sum(a []int) int {
	var s int
	for i := 0; i < len(a); i++ {
		s += a[i]
	}
	return s
}

func zip(a, b []int) [][]int {
	var c [][]int
	for i := 0; i < len(a); i++ {
		c = append(c, []int{a[i], b[i]})
	}
	return c
}

