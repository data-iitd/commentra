package main

import (
	"fmt"
	"math"
)

func main() {
	var N, A, B int64
	fmt.Scan(&N, &A, &B) // Reading input values

	if isValidInput(N, A, B) {
		var k int64 = 0
		if A+B <= N {
			k = calculateK(N, A, B)

			if remainingPartGreaterThanA(N, k, A, B) {
				printResult(N, k, A, B)
			} else {
				printResult(N, k, A, B)
			}
		} else if A+B > N && A <= N {
			printA(A)
		} else {
			printN(N)
		}
	}
}

func isValidInput(n, a, b int64) bool {
	return 1 <= n && n <= int64(math.Pow(10, 18)) && 0 <= a && 0 <= b && 0 < a+b && a+b <= int64(math.Pow(10, 18))
}

func calculateK(n, a, b int64) int64 {
	return n / (a + b)
}

func remainingPartGreaterThanA(n, k, a, b int64) bool {
	return (n - k*(a+b)) > a
}

func printResult(n, k, a, b int64) {
	var result int64
	if remainingPartGreaterThanA(n, k, a, b) {
		result = a*k + (n - k*(a+b)) - (n - (k*(a+b) + a))
	} else {
		result = a*k + (n - k*(a+b))
	}
	fmt.Println(result)
}

func printA(a int64) {
	fmt.Println(a)
}

func printN(n int64) {
	fmt.Println(n)
}

// <END-OF-CODE>
