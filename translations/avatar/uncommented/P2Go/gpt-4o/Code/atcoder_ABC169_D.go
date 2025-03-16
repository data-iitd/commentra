package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	INF = 999999999999999999
	MOD = 1000000007
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader)
	if n == 1 {
		fmt.Println(0)
		return
	}

	fac := primeFactorize(n)
	counts := make(map[int]int)
	for _, p := range fac {
		counts[p]++
	}

	ans := 0
	for _, e := range counts {
		x := e
		for i := 1; i < 99999999; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}
	fmt.Println(ans)
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
	f := 3
	for f*f <= n {
		if n%f == 0 {
			factors = append(factors, f)
			n /= f
		} else {
			f += 2
		}
	}
	if n != 1 {
		factors = append(factors, n)
	}
	return factors
}

// <END-OF-CODE>
