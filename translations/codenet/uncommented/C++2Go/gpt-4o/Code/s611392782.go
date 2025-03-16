package main

import (
	"fmt"
	"strings"
)

func mul(str string, idx *int) int {
	res := int(str[*idx] - '0')
	for *idx+1 < len(str) && str[*idx+1] == '*' {
		*idx += 2
		res *= int(str[*idx] - '0')
	}
	return res
}

func add(str string, idx *int) int {
	res := mul(str, idx)
	for *idx+1 < len(str) && str[*idx+1] == '+' {
		*idx += 2
		res += mul(str, idx)
	}
	return res
}

func bob(str string, idx *int) int {
	res := int(str[*idx] - '0')
	for *idx+1 < len(str) {
		if str[*idx+1] == '+' {
			res += int(str[*idx+2] - '0')
		} else {
			res *= int(str[*idx+2] - '0')
		}
		*idx += 2
	}
	return res
}

func main() {
	var s string
	var d int
	for {
		if _, err := fmt.Scan(&s, &d); err != nil {
			break
		}
		idx := 0
		a := add(s, &idx)
		idx = 0
		b := bob(s, &idx)
		if a == d {
			if b == d {
				fmt.Println("U")
			} else {
				fmt.Println("M")
			}
		} else {
			if b == d {
				fmt.Println("L")
			} else {
				fmt.Println("I")
			}
		}
	}
}

// <END-OF-CODE>
