package main

import (
	"fmt"
	"math"
)

func main() {
	var N, A, B int64
	fmt.Scan(&N, &A, &B)

	k := int64(0)

	if isValidInput(N, A, B) {
		if A+B <= N {
			k = calculateK(N, A, B)

			if remainingPartGreaterThanA(N, k, A) {
				printResult(N, k, A)
			} else {
				printResult(N, k, A)
			}
		} else if A+B > N && A <= N {
			printA()
		} else {
			printN()
		}
	}
}

func isValidInput(n, a, b int64) bool {
	return 1 <= n && n <= int64(math.Pow(10, 18)) && 0 <= a && 0 <= b && 0 < a+b && a+b <= int64(math.Pow(10, 18))
}

func calculateK(n, a, b int64) int64 {
	return n / (a + b)
}

func remainingPartGreaterThanA(n, k, a int64) bool {
	return (n - k*(a+b)) > a
}

func printResult(n, k, a int64) {
	result := int64(0)
	if remainingPartGreaterThanA(n, k, a) {
		result = a*k + (n - k*(a+b)) - (n - (k*(a+b)+a))
	} else {
		result = a*k + (n - k*(a+b))
	}
	fmt.Println(result)
}

func printA() {
	fmt.Println(A)
}

func printN() {
	fmt.Println(N)
}

