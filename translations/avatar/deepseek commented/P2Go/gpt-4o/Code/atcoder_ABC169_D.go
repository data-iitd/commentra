package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

var (
	INF = 999999999999999999999999 // Constant for infinity
	MOD = 1000000007                // Constant for a large prime number
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader) // Read the integer n
	if n == 1 {
		fmt.Println(0) // If n is 1, print 0 and exit
		return
	}

	fac := primeFactorize(n) // Get the prime factorization of n
	counts := make(map[int]int)
	for _, p := range fac {
		counts[p]++
	}

	ans := 0
	for _, e := range counts {
		x := e
		for i := 1; i < math.MaxInt32; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}

	fmt.Println(ans) // Print the final answer
}

func readInt(reader *bufio.Reader) int {
	var n int
	fmt.Fscan(reader, &n)
	return n
}

func primeFactorize(n int) []int {
	var factors []int
	for n%2 == 0 {
		factors = append(factors, 2)
		n /= 2
	}
	for f := 3; f*f <= n; f += 2 {
		for n%f == 0 {
			factors = append(factors, f)
			n /= f
		}
	}
	if n > 1 {
		factors = append(factors, n)
	}
	return factors
}
