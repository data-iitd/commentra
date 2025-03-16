
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func gcd(a, b int) int {
	// Calculate the greatest common divisor (GCD) of two numbers a and b
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	// Calculate the least common multiple (LCM) of two numbers a and b
	return a * b / gcd(a, b)
}

const MOD = 100000007  // Define a constant MOD for modular arithmetic

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)  // Read the number of elements from user input

	fmt.Println("Enter the elements separated by spaces:")
	aStr, _ := reader.ReadString('\n')
	aStr = aStr[:len(aStr)-1]  // Remove the trailing newline character
	a := make([]int, n)         // Initialize a slice to store the list of integers

	for i, s := range strings.Split(aStr, " ") {
		a[i], _ = strconv.Atoi(s)  // Convert each string to an integer and store in the slice
	}

	lcm := 1  // Initialize the variable to store the LCM of the list
	for _, v := range a {
		// Update the LCM by calculating the LCM of the current LCM and the next element
		lcm = lcm * v / gcd(lcm, v)
	}

	ans := lcm  // Initialize the variable to store the final answer
	for _, v := range a {
		// Update the answer by multiplying it with the modular inverse of the current element
		ans = ans * pow(v, MOD-2) % MOD
	}

	fmt.Println(ans)  // Print the result, ensuring it is within the bounds of MOD
}

func pow(x, n int) int {
	// Calculate the modular exponentiation of x to the power of n modulo MOD
	result := 1
	for n > 0 {
		if n&1 == 1 {
			result = result * x % MOD
		}
		x = x * x % MOD
		n >>= 1
	}
	return result
}

