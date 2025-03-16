package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	for a%b != 0 {
		a, b = b, a%b
	}
	return b
}

func solve() {
	s := ""
	fmt.Scan(&s)
	t := ""
	i := 0
	for i < len(s) {
		if s[i] == 'A' {
			t += "A"
			i++
		} else if s[i] == 'B' {
			if i < len(s)-1 {
				if s[i+1] == 'C' {
					t += "D"
					i += 2
				} else {
					t += "X"
					i++
				}
			} else {
				t += "X"
				i++
			}
		} else {
			t += "X"
			i++
		}
	}
	total := 0
	numA := 0
	for i := 0; i < len(t); i++ {
		if t[i] == 'X' {
			numA = 0
		} else {
			if t[i] == 'A' {
				numA++
			} else {
				total += numA
			}
		}
	}
	fmt.Println(total)
}

func main() {
	solve()
}

