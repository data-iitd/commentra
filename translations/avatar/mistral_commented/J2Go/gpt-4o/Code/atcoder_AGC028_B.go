package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin) // Initialize BufferedReader to read input
	nStr, _ := reader.ReadString('\n')   // Read the number of elements in the array
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to integer
	sa, _ := reader.ReadString('\n') // Read the array elements as strings
	saSlice := split(sa[:len(sa)-1]) // Split by space

	a := make([]int, n) // Initialize an integer slice 'a' of size 'n'

	// Parse each string element in the array and store it as an integer in 'a' slice
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(saSlice[i])
	}

	p := int64(1) // Initialize 'p' variable to calculate the factorial of all numbers from 2 to 'n'

	// Calculate the factorial of all numbers from 2 to 'n' and store it in 'p' variable
	for i := 2; i <= n; i++ {
		p = p * int64(i) % mod
	}

	q := make([]int64, n) // Initialize a long slice 'q' of size 'n'
	q[0] = 1              // Initialize the first element of 'q' slice with 1

	// Calculate the values of 'q' slice using the formula (q[i] = q[i-1] + 1/i % mod)
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % mod
	}

	ans := int64(0) // Initialize the answer variable

	// Calculate the answer using the formula ans = sum of (q[i] * a[i] * p) for all i from 0 to n-1
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1 // Calculate the value of 'val' using the formula
		val *= int64(a[i])         // Multiply 'val' with 'a[i]'
		val %= mod                 // Modulo the result with the modulus value
		val *= p                   // Multiply 'val' with 'p'
		val %= mod                 // Modulo the result with the modulus value
		ans += val                 // Add the result to the answer
		ans %= mod                 // Modulo the answer with the modulus value
	}

	fmt.Println(ans) // Print the answer
}

func modinv(a, m int64) int64 { // Method to calculate the modular inverse of 'a' with respect to 'm'
	b := m
	u := int64(1)
	v := int64(0)
	tmp := int64(0)

	// Use extended Euclidean algorithm to find the modular inverse
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

	u %= m // If the result is negative, add 'm' to make it positive
	if u < 0 {
		u += m
	}

	return u // Return the modular inverse
}

func split(s string) []string {
	var result []string
	for _, word := range bufio.NewScanner(strings.NewReader(s)).Split(bufio.ScanWords) {
		result = append(result, word.Text())
	}
	return result
}

// <END-OF-CODE>
