package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read the integer n, which represents the number of elements
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read the next line of input and split it into an array of strings
	sa := strings.Split(readLine(reader), " ")
	
	// Initialize an integer array to hold the parsed values
	a := make([]int, n)
	
	// Parse the string array into an integer array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i])
	}
	
	// Close the BufferedReader as we no longer need it
	
	// Define a modulus value for calculations to prevent overflow
	mod := 1000000007
	
	// Initialize a variable to hold the factorial product
	p := int64(1)
	
	// Calculate the factorial of n modulo mod
	for i := 2; i <= n; i++ {
		p = p * int64(i) % int64(mod)
	}
	
	// Initialize an array to hold cumulative sums of modular inverses
	q := make([]int64, n)
	q[0] = 1 // Base case for the first element
	
	// Calculate the cumulative sum of modular inverses
	for i := 1; i < n; i++ {
		q[i] = (q[i - 1] + modinv(int64(i + 1), mod)) % int64(mod)
	}
	
	// Initialize a variable to hold the final answer
	var ans int64 = 0
	
	// Calculate the final answer using the cumulative sums and input array
	for i := 0; i < n; i++ {
		val := q[i] + q[n - i - 1] - 1
		val *= int64(a[i])
		val %= int64(mod)
		val *= p
		val %= int64(mod)
		ans += val
		ans %= int64(mod)
	}
	
	// Print the final result
	fmt.Println(ans)
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
func modinv(a int64, m int) int64 {
	b := int64(m)
	u := int64(1)
	v := int64(0)
	tmp := int64(0)
	
	// Apply the Extended Euclidean Algorithm
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
	
	// Ensure u is positive and within the modulus
	u %= int64(m)
	if u < 0 {
		u += int64(m)
	}
	
	// Return the modular inverse
	return u
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
