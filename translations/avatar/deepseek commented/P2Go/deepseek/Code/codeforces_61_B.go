package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

// Function to calculate the sum of an arithmetic series from i to n
func sumn(i, n int) float64 {
	return float64((n-i)*(i+n)) / 2
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

// Function to read a single or multiple integer values from input
func value() []int {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	parts := strings.Split(input.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a single or multiple integer values from standard input
func values() []int {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	parts := strings.Split(input.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a list of integers from input
func inlst() []int {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	parts := strings.Split(input.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a list of integers from standard input
func inlsts() []int {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	parts := strings.Split(input.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a single integer from input
func inp() int {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	num, _ := strconv.Atoi(input.Text())
	return num
}

// Function to read a single integer from standard input
func inps() int {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	num, _ := strconv.Atoi(input.Text())
	return num
}

// Function to read a string from input
func instr() string {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	return input.Text()
}

// Function to split a string into a list of words
func stlst() []string {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	parts := strings.Split(input.Text(), " ")
	return parts
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
func f(s string) string {
	r := ""
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r += strings.ToLower(string(i))
		}
	}
	return r
}

// Main logic of the program
func solve() {
	l := []string{}
	for i := 0; i < 3; i++ {
		l = append(l, f(instr()))
	}
	perms := permute(l)
	for i := 0; i < inp(); i++ {
		if contains(f(instr()), perms) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// Helper function to generate permutations
func permute(arr []string) []string {
	var helper func([]string, int)
	res := []string{}

	helper = func(arr []string, n int) {
		if n == 1 {
			res = append(res, strings.Join(arr, ""))
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					arr[0], arr[n-1] = arr[n-1], arr[0]
				} else {
					arr[i], arr[n-1] = arr[n-1], arr[i]
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

// Helper function to check if a string is in the list of permutations
func contains(s string, perms []string) bool {
	for _, perm := range perms {
		if s == perm {
			return true
		}
	}
	return false
}

func main() {
	solve()
}

