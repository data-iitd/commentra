package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Main function definition

	var l, r int64
	var res int64

	l, r = readLongs() // Reading the first and second number from the console

	maxxes := make([]int64, 10) // Creating an array'maxxes' of size 10 to store the maximum numbers that can be formed using each digit

	var temp int64
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Multiply the temporary variable with 10 and add 9 to get the next digit
		maxxes[i] = temp/2*(temp-temp/2) // Calculate and store the maximum number in the 'i'th index of the'maxxes' array
	}

	res = int64(math.Max(float64(mult(l)), float64(res))) // Calculate the product of the first number 'l' with the maximum number that can be formed using its digits and update the result variable
	res = int64(math.Max(float64(mult(r)), float64(res))) // Calculate the product of the second number 'r' with the maximum number that can be formed using its digits and update the result variable

	temp = 0
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Multiply the temporary variable with 10 and add 9 to get the next digit
		if l <= temp/2 && temp/2 <= r { // Check if the range includes the maximum number that can be formed using the 'i'th digit
			res = int64(math.Max(float64(maxxes[i]), float64(res))) // Update the result variable with the maximum number that can be formed using the 'i'th digit if the condition is true
		}
	}

	fmt.Println(res) // Printing the final result
}

func power(a int64) int {
	// Method definition for calculating the power of a number
	res := 0 // Initializing the result variable to 0
	for a > 0 {
		res++ // Increment the result variable
		a = a / 10 // Divide the number by 10 to get the number of digits
	}
	return res // Return the result
}

func mult(a int64) int64 {
	// Method definition for calculating the product of a number with the maximum number that can be formed using its digits
	pow := power(a) // Calculate the power of the number 'a'
	max := int64(0)  // Initializing the maximum variable to 0
	for j := 0; j < pow; j++ {
		// Loop to calculate the maximum number that can be formed using the digits of the number 'a'
		max = max*10 + 9 // Multiply the maximum variable with 10 and add 9 to get the next digit
	}
	return a * (max - a) // Return the product of the number 'a' and the maximum number calculated above
}

func readLongs() (int64, int64) {
	// Method definition for reading two numbers from the console
	var l, r int64
	fmt.Scanf("%d %d", &l, &r) // Reading the first and second number from the console
	return l, r
}

