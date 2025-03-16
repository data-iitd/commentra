package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Step 1: Read the input number n and the array elements
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n := 0
	fmt.Sscanf(input, "%d", &n)

	arrayStr, _ := reader.ReadString('\n')
	sa := make([]string, n)
	for i := 0; i < n; i++ {
		sa[i] = string(arrayStr[i*2])
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Sscanf(sa[i], "%d", &a[i])
	}

	// Step 2: Calculate the factorial of n modulo 10^9 + 7
	const mod = 1000000007
	p := int64(1)
	for i := 2; i <= n; i++ {
		p = p * int64(i) % int64(mod)
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
		val := q[i] + q[n-i-1] - 1
		val *= int64(a[i])
		val %= int64(mod)
		val *= p
		val %= int64(mod)
		ans += val
		ans %= int64(mod)
	}

	// Step 5: Print the final answer
	fmt.Println(ans)
}

// Function to calculate the modular inverse
func modinv(a int64, m int) int64 {
	b := m
	u := int64(1)
	v := int64(0)
	tmp := int64(0)
	for b > 0 {
		t := a / b
		a -= t * b
		tmp = a
		a = b
		b = tmp
		u -= t * v
		tmp = u
		u = v
		v = tmp
	}
	u %= int64(m)
	if u < 0 {
		u += int64(m)
	}
	return u
}

