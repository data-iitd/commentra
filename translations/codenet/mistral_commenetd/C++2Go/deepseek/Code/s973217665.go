package main

import (
	"fmt"
	"math"
)

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	sqrtN := int(math.Sqrt(float64(n)))
	for i := 3; i <= sqrtN; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var p, q int
		fmt.Scan(&p, &q)

		l := int(math.Sqrt(float64(p*p + q*q)))

		isPrime := true

		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				x := i*i + j*j

				if x <= 1 {
					continue
				}
				if x > p*p+q*q {
					continue
				}

				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isPrime = false
					break
				}
			}
			if !isPrime {
				break
			}
		}

		if isPrime {
			fmt.Println("P")
		} else {
			fmt.Println("C")
		}
	}
}

