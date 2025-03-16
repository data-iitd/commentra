
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to get a list of numbers separated by a space
func get_nums_l() []int {
	var s string
	fmt.Scanf("%s", &s)
	var l []int
	for _, v := range strings.Split(s, " ") {
		if v!= "" {
			num, _ := strconv.Atoi(v)
			l = append(l, num)
		}
	}
	return l
}

// Function to get a list of numbers of a given length
func get_nums_n(n int) []int {
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &l[i])
	}
	return l
}

// Function to get all integers from a file
func get_all_int() []int {
	var l []int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		l = append(l, num)
	}
	return l
}

// Function to prime factorize a number
func prime_factorize(n int) []int {
	var a []int
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
	if n!= 1 {
		a = append(a, n)
	}
	return a
}

// Function to calculate the factorial of a number
func factorial(n int) []int {
	var a []int
	for i := 1; i <= n; i++ {
		a = append(a, i)
	}
	return a
}

func main() {
	// Get the number of test cases
	var n int
	fmt.Scanf("%d", &n)

	// Base case for the recursion
	if n == 1 {
		fmt.Println(0)
		return
	}

	// Get the prime factorization of n
	var fac []int
	fac = prime_factorize(n)

	// Initialize variables
	var ans int
	var fac_ map[int]int
	fac_ = make(map[int]int)
	for _, v := range fac {
		fac_[v] += 1
	}

	// Calculate the answer
	for p, e := range fac_ {
		x := e
		for i := 1; i <= 1000000000; i++ {
			if x >= i {
				x -= i
				ans += 1
			} else {
				break
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

