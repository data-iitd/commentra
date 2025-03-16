package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the input from System.in
	reader := bufio.NewReader(os.Stdin)
	// Reading the first line of input and splitting it into an array of strings
	firstLine, _ := reader.ReadString('\n')
	firstLine = strings.TrimSuffix(firstLine, "\n")
	firstLineArray := strings.Split(firstLine, " ")
	// Parsing the first element of the array as an integer representing the size of the array
	n, _ := strconv.Atoi(firstLineArray[0])
	// Reading the second line of input and splitting it into an array of strings
	secondLine, _ := reader.ReadString('\n')
	secondLine = strings.TrimSuffix(secondLine, "\n")
	secondLineArray := strings.Split(secondLine, " ")
	// Creating an integer array of size n
	c := make([]int, n)

	// Initializing the array c with the input values
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(secondLineArray[i])
	}

	// Checking if the size of the array is 1
	if n == 1 {
		// Printing the result for the case when the size of the array is 1
		fmt.Println(c[0] * 2 % 1000000007)
		return
	}

	// Sorting the array c in parallel using Arrays.parallelSort() method
	// Arrays.parallelSort(c)

	// Calculating the values of b and a
	b := power(2, n)
	a := power(2, n-2)

	// Initializing the variable ans to 0
	ans := 0

	// Iterating through the array from index 2 to n+1
	for i := 2; i <= n+1; i++ {
		// Calculating the value of val using the current index i and the previously calculated value a
		val := a * i % 1000000007

		// Multiplying the value of val with the current element of the array c[n+1-i]
		val *= c[n+1-i]

		// Taking the modulus of the product to ensure the result is within the range of modulus
		val %= 1000000007

		// Adding the value of val to the variable ans
		ans += val

		// Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
		ans %= 1000000007
	}

	// Multiplying the value of ans with the value of b
	ans *= b

	// Taking the modulus of the product to ensure the result is within the range of modulus
	ans %= 1000000007

	// Printing the final result
	fmt.Println(ans)
}

// Static method to calculate the power of a number x raised to the power n
func power(x, n int) int {
	if n == 0 { // Base case when n is 0
		return 1
	}

	// Recursively calculating the square of x raised to the power n/2
	val := power(x, n/2)

	// If n is odd, multiplying the result with x
	if n%2 == 1 {
		val *= x
	}

	// Returning the final result
	return val
}

// 