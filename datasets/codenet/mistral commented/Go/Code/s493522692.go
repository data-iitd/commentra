// Util functions
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Util functions
func nextStr() string {
	// Scans the next token, a rune, into sc.Text().
	sc.Scan()
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text()
}

// With a comment explaining what the function does:
// Scans the next token, a rune, into sc.Text() and returns it as a string.
func nextStr() string {
	// Scans the next token, a rune, into sc.Text().
	sc.Scan()
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text()
}

func nextInt() int {
	// Scans the next token, a string, into sc.Text().
	// Converts the string to an integer using strconv.Atoi() and returns it.
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	if e := recover(); e != nil {
		panic(e)
	}
	return i
}

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and converts it to an integer.
func nextInt() int {
	// Scans the next token, a string, into sc.Text().
	sc.Scan()
	// Converts the string to an integer using strconv.Atoi().
	i, _ := strconv.Atoi(sc.Text())
	// Recovers from any panic that might occur during the conversion.
	if e := recover(); e != nil {
		panic(e)
	}
	// Returns the integer.
	return i
}

// Helper functions for mathematical operations
func maxInt(a, b int) int {
	// Returns the maximum of two integers.
	if a > b {
		return a
	} else {
		return b
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two integers.
func maxInt(a, b int) int {
	// If 'a' is greater than 'b', return 'a'.
	if a > b {
		return a
	} else {
		// Otherwise, return 'b'.
		return b
	}
}

func minInt(a, b int) int {
	// Returns the minimum of two integers.
	if a > b {
		return b
	} else {
		return a
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two integers.
func minInt(a, b int) int {
	// If 'a' is greater than 'b', return 'b'.
	if a > b {
		return b
	} else {
		// Otherwise, return 'a'.
		return a
	}
}

func absInt(a int) int {
	// Returns the absolute value of an integer.
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// With a comment explaining what the function does:
// Returns the absolute value of an integer.
func absInt(a int) int {
	// If the integer is non-negative, return it as is.
	if a >= 0 {
		return a
	} else {
		// Otherwise, return the negative of the integer.
		return -a
	}
}

func absFloat64(a float64) float64 {
	// Returns the absolute value of a floating-point number.
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// With a comment explaining what the function does:
// Returns the absolute value of a floating-point number.
func absFloat64(a float64) float64 {
	// If the floating-point number is non-negative, return it as is.
	if a >= 0 {
		return a
	} else {
		// Otherwise, return the negative of the floating-point number.
		return -a
	}
}

func maxFloat64(a, b float64) float64 {
	// Returns the maximum of two floating-point numbers.
	if a > b {
		return a
	} else {
		return b
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two floating-point numbers.
func maxFloat64(a, b float64) float64 {
	// If 'a' is greater than 'b', return 'a'.
	if a > b {
		return a
	} else {
		// Otherwise, return 'b'.
		return b
	}
}

func minFloat64(a, b float64) float64 {
	// Returns the minimum of two floating-point numbers.
	if a > b {
		return b
	} else {
		return a
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two floating-point numbers.
func minFloat64(a, b float64) float64 {
	// If 'a' is greater than 'b', return 'b'.
	if a > b {
		return b
	} else {
		// Otherwise, return 'a'.
		return a
	}
}

func str2Int(s string) int {
	// Converts a string to an integer.
	n, _ := strconv.Atoi(s)
	return n
}

// With a comment explaining what the function does:
// Converts a string to an integer.
func str2Int(s string) int {
	// Attempts to convert the string to an integer using strconv.Atoi().
	n, _ := strconv.Atoi(s)
	// Returns the integer.
	return n
}

func reverse(s string) string {
	// Reverses a given string.
	runes := []rune(s)
	// Iterates through the rune slice from both ends and swaps the elements.
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		// Swaps the elements at the current indices.
		runes[i], runes[j] = runes[j], runes[i]
	}
	// Returns the reversed string.
	return string(runes)
}

// With a comment explaining what the function does:
// Reverses a given string.
func reverse(s string) string {
	// Initializes a rune slice with the given string.
	runes := []rune(s)
	// Iterates through the rune slice from both ends and swaps the elements.
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		// Swaps the elements at the current indices.
		runes[i], runes[j] = runes[j], runes[i]
	}
	// Returns the reversed string.
	return string(runes)
}

func powInt(p, q int) int {
	// Calculates 'p' raised to the power of 'q'.
	return int(math.Pow(float64(p), float64(q)))
}

// With a comment explaining what the function does:
// Calculates 'p' raised to the power of 'q'.
func powInt(p, q int) int {
	// Calculates 'p' raised to the power of 'q' using the math.Pow() function.
	return int(math.Pow(float64(p), float64(q)))
}

func isPrime(x int) bool {
	// Checks if a given number is prime.
	if x == 1 {
		// 1 is not a prime number.
		return false
	}
	if x == 2 {
		// 2 is a prime number.
		return true
	}
	// If the number is even, it's not a prime number.
	if x%2 == 0 {
		return false
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	b := true
	rootx := int(math.Sqrt(float64(x)))
	i := 3
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	for i <= rootx {
		// If 'x' is divisible by the current number, it's not a prime number.
		if x%i == 0 {
			b = false
			break
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2
	}
	// Returns the result.
	return b
}

// With a comment explaining what the function does:
// Checks if a given number is prime.
func isPrime(x int) bool {
	// If the number is 1, it's not a prime number.
	if x == 1 {
		return false
	}
	// If the number is 2, it's a prime number.
	if x == 2 {
		return true
	}
	// If the number is even, it's not a prime number.
	if x%2 == 0 {
		return false
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	b := true
	rootx := int(math.Sqrt(float64(x)))
	i := 3
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	for i <= rootx {
		// If 'x' is divisible by the current number, it's not a prime number.
		if x%i == 0 {
			b = false
			break
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2
	}
	// Returns the result.
	return b
}

func PrimeFactors(n int) (pfs []int) {
	// Finds the prime factors of a given number.
	// Get the number of 2s that divide n
	for n%2 == 0 {
		// Appends 2 to the result slice.
		pfs = append(pfs, 2)
		// Divides n by 2.
		n = n / 2
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for i := 3; i*i <= n; i = i + 2 {
		// While i divides n, appends i to the result slice and divides n by i.
		for n%i == 0 {
			pfs = append(pfs, i)
			n = n / i
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if n > 2 {
		// Appends n to the result slice.
		pfs = append(pfs, n)
	}

	// Returns the result.
	return
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
func PrimeFactors(n int) (pfs []int) {
	// Initializes an empty result slice.
	pfs = make([]int, 0)

	// Get the number of 2s that divide n
	for n%2 == 0 {
		// Appends 2 to the result slice.
		pfs = append(pfs, 2)
		// Divides n by 2.
		n = n / 2
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for i := 3; i*i <= n; i = i + 2 {
		// While i divides n, appends i to the result slice and divides n by i.
		for n%i == 0 {
			pfs = append(pfs, i)
			n = n / i
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if n > 2 {
		// Appends n to the result slice.
		pfs = append(pfs, n)
	}

	// Returns the result.
	return
}

func PrimeFactorsMap(n int) map[int]int {
	// Finds the prime factors of a given number and returns them as a map.
	pfs := make(map[int]int)
	// Get the number of 2s that divide n
	for n%2 == 0 {
		// Sets the key to 2 and the value to the number of occurrences.
		pfs[2]++
		// Divides n by 2.
		n = n / 2
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for i := 3; i*i <= n; i = i + 2 {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		for n%i == 0 {
			pfs[i]++
			n = n / i
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if n > 2 {
		// Sets the key to n and the value to the number of occurrences.
		pfs[n]++
	}

	// Returns the result.
	return pfs
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number and returns them as a map.
func PrimeFactorsMap(n int) map[int]int {
	// Initializes an empty map.
	pfs := make(map[int]int)

	// Get the number of 2s that divide n
	for n%2 == 0 {
		// Sets the key to 2 and the value to the number of occurrences.
		pfs[2]++
		// Divides n by 2.
		n = n / 2
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for i := 3; i*i <= n; i = i + 2 {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		for n%i == 0 {
			pfs[i]++
			n = n / i
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if n > 2 {
		// Se