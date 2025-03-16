
package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func solve() {
	s := readString()
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
		} else if t[i] == 'A' {
			numA++
		}
		total += numA
	}
	fmt.Println(total)
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func main() {
	solve()
}

