package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	br  = bufio.NewReader(os.Stdin)
	pw  = bufio.NewWriter(os.Stdout)
	st  *strings.Tokenizer
)

// Reads an integer from the standard input using a strings.Tokenizer.
func readInt() (int, error) {
	for st == nil || !st.Scan() {
		line, err := br.ReadString('\n')
		if err != nil {
			return 0, err
		}
		st = strings.NewTokenizer(line)
	}
	return strconv.Atoi(st.Scan())
}

// The main function is the entry point of the program.
func main() {
	fmt.Fprintln(pw, solve())
	pw.Flush()
}

// This function contains the logic to solve the problem.
func solve() int {
	K, err := readInt()
	if err != nil {
		fmt.Println("Error reading integer:", err)
		return -1
	}

	// Check if K is divisible by 2 or 5, return -1 if true.
	if K%2 == 0 || K%5 == 0 {
		return -1
	}

	// If K is divisible by 7, divide K by 7.
	if K%7 == 0 {
		K /= 7
	}

	// Multiply K by 9.
	K *= 9

	// Initialize the answer and the remainder.
	ans := 1
	remainder := 10 % K

	// Loop to find the number of digits required to form a number that is a multiple of K.
	for remainder != 1 {
		ans++
		remainder = (remainder * 10) % K
	}

	return ans
}
