
package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const MOD = 100000007

	scanner.Scan()
	R := scanner.Int()
	if R < 1200 {
		fmt.Println("ABC")
	} else if R >= 2800 {
		fmt.Println("AGC")
	} else {
		fmt.Println("ARC")
	}
}

