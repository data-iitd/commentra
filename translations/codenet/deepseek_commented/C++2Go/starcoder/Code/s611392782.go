
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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
	*idx++
	for *idx < len(str) && str[*idx] == '*' {
		*idx++
		res *= int(str[*idx] - '0')
		*idx++
	}
	return res
}

// This function adds the results of multiple calls to mul by handling '+' operations.
func add(str string, idx *int) int {
	res := mul(str, idx)
	for *idx < len(str) && str[*idx] == '+' {
		*idx++
		res += mul(str, idx)
	}
	return res
}

// This function performs the same operations as add but uses a different approach.
func bob(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
	*idx++
	for *idx < len(str) {
		if str[*idx] == '+' {
			*idx++
			res += int(str[*idx] - '0')
		} else {
			*idx++
			res *= int(str[*idx] - '0')
		}
		*idx++
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s := scanner.Text()
		d, _ := strconv.Atoi(s[strings.Index(s, " ")+1:])
		s = s[:strings.Index(s, " ")]
		idx := 0
		a := add(s, &idx)  // Calculate the result using the add function
		idx = 0
		b := bob(s, &idx)  // Calculate the result using the bob function
		if a == d {
			fmt.Println("U")  // Output based on both results
		} else {
			fmt.Println("L")  // Output based on both results
		}
	}
}

