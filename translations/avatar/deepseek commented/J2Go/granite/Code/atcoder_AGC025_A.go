

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func sum(a int) int {
	ans := 0
	for a >= 10 {
		ans += a % 10
		a /= 10
	}
	ans += a
	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(text)

	// Calculate n as half of N if N is even, or half of N plus one if N is odd
	var m int
	if n%2 == 0 {
		m = n / 2
	} else {
		m = (n + 1) / 2
	}

	// Initialize ans with the sum of digits of 1 and N-1
	ans := sum(1) + sum(n-1)

	// Iterate from 1 to n to find the minimum sum of digits of A and N-A
	for a := 1; a <= m; a++ {
		if sum(a)+sum(n-a) < ans {
			ans = sum(a) + sum(n-a)
		}
	}

	// Print the minimum ans
	fmt.Println(ans)
}

