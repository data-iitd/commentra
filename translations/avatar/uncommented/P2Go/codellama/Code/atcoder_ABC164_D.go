
package main

import "fmt"

func main() {
	s, l := (input(), 2019)
	m, a, r := ([]int{1} + make([]int, l), 0, 0)
	for i, e := range s[:len(s)-1] {
		a += int(e) * pow(10, i, l)
		r += m[a%l]
		m[a%l] += 1
	}
	fmt.Println(r)
}

func pow(a, b, c int) int {
	return (a * b) % c
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

