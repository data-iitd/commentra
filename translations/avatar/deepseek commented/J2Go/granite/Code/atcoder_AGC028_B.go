

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
	n, _ := strconv.Atoi(reader.ReadLine())
	sa := reader.ReadLine()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i*2 : i*2+2])
	}

	// Step 2: Calculate the factorial of n modulo 10^9 + 7
	mod := 1000000007
	p := int64(1)
	for i := 2; i <= n; i++ {
		p = p * int64(i) % int64(mod)
	}

	// Step 3: Calculate the inverse modulo for each number from 2 to n
	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), int64(mod))) % int64(mod)
	}

	// Step 4: Calculate the answer using the given formula
	ans := int64(0)
	for i := 0; i < n; i++ {
		val := (q[i] + q[n-i-1] - 1) * int64(a[i]) % int64(mod)
		val = val * p % int64(mod)
		ans = (ans + val) % int64(mod)
	}

	// Step 5: Print the final answer
	fmt.Println(ans)
}

// Function to calculate the modular inverse
func modinv(a, m int64) int64 {
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
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

// END-OF-CODE