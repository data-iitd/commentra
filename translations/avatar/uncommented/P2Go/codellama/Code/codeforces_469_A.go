
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var max_level int
	fmt.Scan(&max_level)
	var x, y []int
	fmt.Scan(&x)
	fmt.Scan(&y)
	x = x[1:]
	y = y[1:]
	x = removeDuplicates(x)
	y = removeDuplicates(y)
	if contains(x, 0) {
		x = remove(x, 0)
	} else if contains(y, 0) {
		y = remove(y, 0)
	}
	z := union(x, y)
	if len(z) != max_level {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}

func removeDuplicates(s []int) []int {
	m := make(map[int]bool)
	for _, v := range s {
		m[v] = true
	}
	r := make([]int, 0)
	for k := range m {
		r = append(r, k)
	}
	return r
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func remove(s []int, e int) []int {
	for i, a := range s {
		if a == e {
			return append(s[:i], s[i+1:]...)
		}
	}
	return s
}

func union(s1, s2 []int) []int {
	m := make(map[int]bool)
	for _, v := range s1 {
		m[v] = true
	}
	for _, v := range s2 {
		m[v] = true
	}
	r := make([]int, 0)
	for k := range m {
		r = append(r, k)
	}
	return r
}

