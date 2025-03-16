
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input
func input() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a list of integers from a single line of input
func get_nums_l() []int {
	line := input()
	nums := strings.Split(line, " ")
	nums_l := make([]int, len(nums))
	for i, num := range nums {
		nums_l[i], _ = strconv.Atoi(num)
	}
	return nums_l
}

// Function to read 'n' integers from input, one per line
func get_nums_n(n int) []int {
	nums_l := make([]int, n)
	for i := 0; i < n; i++ {
		nums_l[i], _ = strconv.Atoi(input())
	}
	return nums_l
}

// Function to read all integers from standard input
func get_all_int() []int {
	var nums_l []int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		nums_l = append(nums_l, num)
	}
	return nums_l
}

// Generator function to yield elements from an iterable within a specified range
func rangeI(it []int, l, r int) []int {
	for i, e := range it {
		if l <= i < r {
			yield e
		} else if l >= r {
			break
		}
	}
}

// Debugging function to print debug messages to stderr
func log(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

// Define a large constant for infinity
const INF = 999999999999999999999999

// Define a modulus constant for calculations
const MOD = 10 ** 9 + 7

// Read an integer 'n' from input
func main() {
	n, _ := strconv.Atoi(input())
	if n == 1 {
		fmt.Println(0)
		return
	}
	fac_ := prime_factorize(n)
	fac := make(map[int]int)
	for _, p := range fac_ {
		fac[p]++
	}
	ans := 0
	for p, e := range fac {
		x := e
		for i := 1; i < 99999999; i++ {
			if x >= i {
				x -= i
				ans += 1
			} else {
				break
			}
		}
	}
	fmt.Println(ans)
}

// Function to perform prime factorization of a number
func prime_factorize(n int) []int {
	a := make([]int, 0)
	for n % 2 == 0 {
		a = append(a, 2)
		n /= 2
	}
	f := 3
	for f*f <= n {
		if n % f == 0 {
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

