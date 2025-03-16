

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to find prime numbers up to a given limit
func prime(num int) []bool {
	flag := make([]bool, num+1)

	// Loop through numbers from 2 to num
	for i := 2; i*i <= num; i++ {
		// If a number is not marked as composite, mark all its multiples as composite
		if!flag[i] {
			for j := 2; i*j <= num; j++ {
				flag[i*j] = true
			}
		}
	}

	return flag
}

func main() {
	var n int
	var cnt int
	var i int
	var flag []bool

	// Call prime function to find prime numbers up to 50000
	flag = prime(50000)

	// Loop until user inputs 0
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
		// Break the loop if user inputs 0
		if n == 0 {
			break
		}
		// Initialize i and cnt to 0
		i = 2
		cnt = 0
		// Loop through numbers from 2 to square root of n
		for i*i <= n {
			// If i and n-i are both prime, increment cnt
			if!flag[i] &&!flag[n-i] {
				cnt++
			}
			// Increment i for next iteration
			i++
		}
		// Print the result
		fmt.Println(cnt)
	}
}

