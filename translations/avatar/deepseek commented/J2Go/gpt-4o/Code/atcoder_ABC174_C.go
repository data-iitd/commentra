package main

import (
	"bufio"
	"fmt"
	"os"
)

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	var num int
	fmt.Sscan(scanner.Text(), &num)
	return num
}

func solve(scanner *bufio.Scanner) int {
	K := readInt(scanner)

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
		remainder = remainder * 10 % K
	}

	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println(solve(scanner))
}

// <END-OF-CODE>
