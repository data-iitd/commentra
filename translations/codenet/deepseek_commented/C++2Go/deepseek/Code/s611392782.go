package main

import (
	"fmt"
	"strconv"
	"strings"
)

// This function multiplies consecutive digits until it encounters a '+' or the end of the string.
func mul(str string, idx int) int {
	res, _ := strconv.Atoi(string(str[idx]))
	for idx+1 < len(str) && str[idx+1] == '*' {
		idx += 2
		num, _ := strconv.Atoi(string(str[idx]))
		res *= num
	}
	return res
}

// This function adds the results of multiple calls to mul by handling '+' operations.
func add(str string, idx int) int {
	res := mul(str, idx)
	for idx+1 < len(str) && str[idx+1] == '+' {
		idx += 2
		res += mul(str, idx)
	}
	return res
}

// This function performs the same operations as add but uses a different approach.
func bob(str string, idx int) int {
	res, _ := strconv.Atoi(string(str[idx]))
	for idx+1 < len(str) {
		if str[idx+1] == '+' {
			idx += 2
			num, _ := strconv.Atoi(string(str[idx]))
			res += num
		} else {
			idx += 2
			num, _ := strconv.Atoi(string(str[idx]))
			res *= num
		}
	}
	return res
}

func main() {
	var s string
	var d int
	for {
		_, err := fmt.Scan(&s, &d)
		if err != nil {
			break
		}
		idx := 0
		a := add(s, idx)  // Calculate the result using the add function
		idx = 0
		b := bob(s, idx)  // Calculate the result using the bob function
		if a == d {
			if b == d {
				fmt.Println("U")  // Output based on both results
			} else {
				fmt.Println("M")  // Output based on both results
			}
		} else {
			if b == d {
				fmt.Println("L")  // Output based on both results
			} else {
				fmt.Println("I")  // Output based on both results
			}
		}
	}
}

