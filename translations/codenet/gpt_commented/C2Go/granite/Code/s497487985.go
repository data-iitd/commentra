
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
func gcd(a, b int64) int64 {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

// Function to calculate the least common multiple (LCM) using GCD
func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int64
	scanner.Scan()
	n, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	var k int64
	scanner.Scan()
	k, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	var q int64
	scanner.Scan()
	q, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	a := make([]int64, q)
	for i := int64(0); i < q; i++ {
		scanner.Scan()
		a[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	point := make([]int64, n)
	for i := int64(0); i < q; i++ {
		point[a[i]-1]++
	}
	for i := int64(0); i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
