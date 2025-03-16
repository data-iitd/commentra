package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read a list of integers from input
func readInts() []int {
	var A []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	for _, s := range strings.Split(scanner.Text(), " ") {
		i, _ := strconv.Atoi(s)
		A = append(A, i)
	}
	return A
}

// Function to print a list of integers to output
func printInts(A []int) {
	for _, i := range A {
		fmt.Printf("%d ", i)
	}
	fmt.Println()
}

// Function to find the median of a list of integers
func findMedian(A []int) int {
	n := len(A)
	if n%2 == 0 {
		return (A[n/2] + A[n/2-1]) / 2
	}
	return A[n/2]
}

// Function to find the gcd of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to find the lcm of two integers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum := 0
	for i := 1; i <= 1<<n; i++ {
		sum += findMedian(A)
	}
	return sum
}

// Function to find the sum of all subsets of a list of integers
func findSumOfSubsets(A []int) int {
	n := len(A)
	sum :