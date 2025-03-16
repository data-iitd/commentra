package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Read the input number n and the array elements
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Remove newline character
	saStr, _ := reader.ReadString('\n')
	sa := split(saStr[:len(saStr)-1]) // Remove newline character
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i])
	}

	// Step 2: Calculate the factorial of n modulo 10^9 + 7
	mod := int64(1000000007)
	p := int64(1)
	for i := 2; i <= n; i++ {
		p = p * int64(i) % mod
	}

	// Step 3: Calculate the inverse modulo for each number from 2 to n
	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % mod
	}

	// Step 4: Calculate the answer using the given formula
	ans := int64(0)
	for i := 0; i < n; i++ {
		val := (q[i] + q[n-i-1] - 1) % mod
		val = (val * int64(a[i])) % mod
		val = (val * p) % mod
		ans = (ans + val) % mod
	}

	// Step 5: Print the final answer
	fmt.Println(ans)
}

// Function to calculate the modular inverse
func modinv(a, m int64) int64 {
	b := m
	u := int64(1)
	v := int64(0)
	for b > 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

// Helper function to split a string by spaces
func split(s string) []string {
	return bufio.NewScanner(strings.NewReader(s)).Split(bufio.ScanWords)
}

// Note: You may need to import "strings" for the split function.
