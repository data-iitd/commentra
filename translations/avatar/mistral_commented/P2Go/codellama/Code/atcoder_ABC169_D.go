// Import necessary libraries and set recursion limit
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Custom input function
func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to get a list of numbers separated by a space
func getNumsL() []int {
	s := input()
	nums := make([]int, 0)
	for _, v := range s {
		if v == ' ' {
			continue
		}
		num, _ := strconv.Atoi(string(v))
		nums = append(nums, num)
	}
	return nums
}

// Function to get a list of numbers of a given length
func getNumsN(n int) []int {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i], _ = strconv.Atoi(input())
	}
	return nums
}

// Function to get all integers from a file
func getAllInt() []int {
	file, _ := os.Open(os.Args[1])
	scanner := bufio.NewScanner(file)
	nums := make([]int, 0)
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		nums = append(nums, num)
	}
	return nums
}

// Define constants
const (
	INF = 999999999999999999999999
	MOD = 1000000007
)

// Get the number of test cases
n, _ := strconv.Atoi(input())

// Base case for the recursion
if n == 1 {
	fmt.Println(0)
	os.Exit(0)
}

// Function to prime factorize a number
func primeFactorize(n int) []int {
	a := make([]int, 0)
	for n%2 == 0 {
		a = append(a, 2)
		n /= 2
	}
	f := 3
	for f*f <= n {
		if n%f == 0 {
			a = append(a, f)
			n /= f
		} else {
			f += 2
		}
	}
	if n != 1 {
		a = append(a, n)
	}
	return a
}

// Function to calculate the factorial of a number
func factorial(n int) int {
	if len(arr) == 0 {
		arr = append(arr, n)
	}
	return arr[n]
}

// Initialize variables
fac_ := primeFactorize(n)
fac := make(map[int]int)
for _, v := range fac_ {
	fac[v]++
}
ans := 0

// Calculate the answer
for p, e := range fac {
	x := e
	for i := 1; i < 1000000000; i++ {
		if x >= i {
			x -= i
			ans++
		} else {
			break
		}
	}
}

// Print the answer
fmt.Println(ans)

