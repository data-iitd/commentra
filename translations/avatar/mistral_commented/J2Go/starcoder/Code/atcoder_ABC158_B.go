
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)

	var n, a, b, k int64

	fmt.Fscan(scan, &n)
	fmt.Fscan(scan, &a)
	fmt.Fscan(scan, &b)

	if isValidInput(n, a, b) {
		if a+b <= n {
			k = calculateK(n, a, b)
			if remainingPartGreaterThanA(n, k, a) {
				printResult(n, k, a)
			} else {
				printResult(n, k, a)
			}
		} else if a+b > n && a <= n {
			printA()
		} else {
			printN()
		}
	}
}

func isValidInput(n, a, b int64) bool {
	return 1 <= n && n <= math.Pow(10, 18) && 0 <= a && 0 <= b && 0 < a+b && a+b <= math.Pow(10, 18)
}

func calculateK(n, a, b int64) int64 {
	return n / (a + b)
}

func remainingPartGreaterThanA(n, k, a int64) bool {
	return n-k*(a+b) > a
}

func printResult(n, k, a int64) {
	var result int64
	if remainingPartGreaterThanA(n, k, a) {
		result = a*k + (n-k*(a+b)) - (n-(k*(a+b)+a))
	} else {
		result = a*k + (n-k*(a+b))
	}
	fmt.Println(result)
}

func printA() {
	fmt.Println(a)
}

func printN() {
	fmt.Println(n)
}

