package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

func valid(i, j, n, m int) bool {
	return i < n && i >= 0 && j >= 0 && j < m
}

func sumn(i, n int) float64 {
	return float64(n-i) * float64(i+n) / 2
}

func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

func values() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

func inlst() []int {
	var n int
	fmt.Scan(&n)
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}
	return lst
}

func inlsts() []int {
	var n int
	fmt.Scan(&n)
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}
	return lst
}

func inp() int {
	var n int
	fmt.Scan(&n)
	return n
}

func inps() int {
	var n int
	fmt.Scan(&n)
	return n
}

func instr() string {
	var s string
	fmt.Scan(&s)
	return s
}

func stlst() []string {
	var s string
	fmt.Scan(&s)
	return strings.Fields(s)
}

func f(s string) string {
	var r strings.Builder
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r.WriteRune(strings.ToLower(i))
		}
	}
	return r.String()
}

func solve() {
	l := make([]string, 0, 3)
	for i := 0; i < 3; i++ {
		var input string
		fmt.Scan(&input)
		l = append(l, f(input))
	}
	
	// Generate permutations
	permutations := make(map[string]struct{})
	var permute func([]string, int)
	permute = func(arr []string, n int) {
		if n == 1 {
			permutations[strings.Join(arr, "")] = struct{}{}
			return
		}
		for i := 0; i < n; i++ {
			permute(arr, n-1)
			if n%2 == 1 {
				arr[0], arr[n-1] = arr[n-1], arr[0]
			} else {
				arr[i], arr[n-1] = arr[n-1], arr[i]
			}
		}
	}
	permute(l, len(l))

	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var input string
		fmt.Scan(&input)
		if _, exists := permutations[f(input)]; exists {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

func main() {
	solve()
}

// <END-OF-CODE>
