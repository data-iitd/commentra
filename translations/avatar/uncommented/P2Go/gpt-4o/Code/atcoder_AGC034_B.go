package main

import (
	"fmt"
)

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func solve() {
	var s string
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
	INF := 10e25
	mod := 7 + 1e9
}

func main() {
	solve()
}

// <END-OF-CODE>
