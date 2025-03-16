
// ACM-ICPCアジア地区予選2014 B. Miscalculation

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// This function multiplies consecutive digits until it encounters a '+' or the end of the string.
func mul(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
	for *idx+1 < len(str) && str[*idx+1] == '*' {
		*idx += 2
		res *= int(str[*idx]-'0')
	}
	return res
}

// This function adds the results of multiple calls to mul by handling '+' operations.
func add(str string, idx *int) int {
	res := mul(str, idx)
	for *idx+1 < len(str) && str[*idx+1] == '+' {
		*idx += 2
		res += mul(str, idx)
	}
	return res
}

// This function performs the same operations as add but uses a different approach.
func bob(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
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
	scanner := bufio.NewScanner(os.Stdin)
	const initialIdx = 0
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		s := fields[0]
		d, _ := strconv.Atoi(fields[1])
		idx := initialIdx
		a := add(s, &idx) // Calculate the result using the add function
		idx = initialIdx
		b := bob(s, &idx) // Calculate the result using the bob function
		if a == d {
			fmt.Print("U")
		} else {
			fmt.Print("L")
		}
		if b == d {
			fmt.Println("U")
		} else {
			fmt.Println("L")
		}
	}
}

