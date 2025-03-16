package main

import (
	"fmt"
	"math"
)

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)
	for n > 0 {
		n--
		var p, q int
		fmt.Scan(&p, &q)
		l := int(math.Sqrt(float64(p*p + q*q)))
		isPrime := true
		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				x := i*i + j*j
				if x <= 1 || x >= p*p+q*q {
					continue
				}
				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isPrime = false
				}
			}
		}
		if isPrime {
			fmt.Println("P")
		} else {
			fmt.Println("C")
		}
	}
}

