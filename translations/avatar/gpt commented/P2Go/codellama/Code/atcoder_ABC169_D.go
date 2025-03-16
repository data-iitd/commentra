
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Function to read a list of integers from a single line of input
func getNumsL() []int {
	s := input()
	nums := strings.Split(s, " ")
	numsL := make([]int, len(nums))
	for i, v := range nums {
		numsL[i], _ = strconv.Atoi(v)
	}
	return numsL
}

// Function to read 'n' integers from input, one per line
func getNumsN(n int) []int {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = int(input())
	}
	return nums
}

// Function to read all integers from standard input
func getAllInt() []int {
	var nums []int
	for {
		s := input()
		if s == "" {
			break
		}
		num, _ := strconv.Atoi(s)
		nums = append(nums, num)
	}
	return nums
}

// Generator function to yield elements from an iterable within a specified range
func rangeI(it []int, l, r int) []int {
	var res []int
	for i, e := range it {
		if l <= i && i < r {
			res = append(res, e)
		} else if l >= r {
			break
		}
	}
	return res
}

// Debugging function to print debug messages to stderr
func log(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

// Define a large constant for infinity
const INF = 999999999999999999999999

// Define a modulus constant for calculations
const MOD = 1000000007

// Read an integer 'n' from input
var n int
fmt.Scan(&n)

// If n is 1, print 0 and exit
if n == 1 {
	fmt.Println(0)
	os.Exit(0)
}

// Function to perform prime factorization of a number
func primeFactorize(n int) []int {
	var a []int
	// Divide n by 2 until it is odd
	for n%2 == 0 {
		a = append(a, 2)
		n /= 2
	}

	// Check for odd factors from 3 upwards
	f := 3
	for f*f <= n {
		if n%f == 0 {
			a = append(a, f)
			n /= f
		} else {
			f += 2
		}
	}

	// If n is still greater than 1, it is a prime factor
	if n != 1 {
		a = append(a, n)
	}

	return a
}

// Perform prime factorization on n
var fac_ = primeFactorize(n)

// Count the occurrences of each prime factor
var fac = make(map[int]int)
for _, v := range fac_ {
	fac[v]++
}

// Initialize the answer variable
var ans int

// Calculate the number of ways to express the prime factors
for p, e := range fac {
	x := e
	// For each prime factor's exponent, calculate how many times it can be used
	for i := 1; i < 99999999; i++ {
		if x >= i {
			x -= i
			ans++
		} else {
			break
		}
	}
}

// Print the final answer
fmt.Println(ans)

