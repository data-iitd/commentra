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

func solve(K int) int {
	if K%2 == 0 || K%5 == 0 {
		return -1
	}
	if K%7 == 0 {
		K /= 7
	}
	K *= 9
	ans := 1
	remainder := 10 % K
	for remainder != 1 {
		ans++
		remainder = remainder * 10 % K
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	K := readInt(scanner)
	fmt.Println(solve(K))
}

// <END-OF-CODE>
