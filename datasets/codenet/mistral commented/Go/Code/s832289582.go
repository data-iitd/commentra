// Package main is the entry point of the program
package main

import (
	"bufio" // We import bufio package for reading input
	"fmt"   // We import fmt package for printing output
	"os"    // We import os package for reading from standard input
	"strconv" // We import strconv package for converting string to integer
)

// N: [1, 2e5] // We define N as an integer variable with the range [1, 2e5]
// len(S) = N   // The length of string S is equal to N
// P: [2, 10000], prime // We define P as an integer variable with the range [2, 10000] and prime
func main() {
	sc := newInputScanner(true, 256) // We create an instance of inputScanner with scanWords enabled and a buffer size of 256 KB
	N, P, S := sc.nextInt(), sc.nextInt(), sc.nextStr() // We read N, P, and S from the standard input using inputScanner
	answer := checkSubNumbers(N, P, S) // We call checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
	fmt.Println(answer) // We print the answer using fmt.Println
}

// checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
func checkSubNumbers(N int, P int, S string) int {
	// Switch statement to check if P is equal to 2 or 5
	switch P {
	case 2, 5:
		return checkTwoOrFive(N, P, S) // If P is equal to 2 or 5, we call checkTwoOrFive function
	default:
		return checkNotTwoNorFive(N, P, S) // If P is not equal to 2 or 5, we call checkNotTwoNorFive function
	}
}

// checkTwoOrFive function checks if any subnumber of given string S is divisible by prime number P equal to 2 or 5
func checkTwoOrFive(N int, P int, S string) int {
	answer := 0 // We initialize answer variable as 0
	var n int // We define an integer variable n
	// We iterate through the string S from the last character to the first character
	for i := N - 1; i >= 0; i-- {
		// We convert the substring from i to i+1 to an integer n
		n, _ = strconv.Atoi(S[i : i+1])
		// If n is divisible by P, we add its index to the answer variable
		if n%P == 0 {
			answer += i + 1
		}
	}
	return answer
}

// checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
func checkNotTwoNorFive(N int, P int, S string) int {
	multiplier := 1 // We initialize multiplier variable as 1
	answer := 0     // We initialize answer variable as 0
	// We create a slice of length P for storing the count of remainders
	remainderLookup := make([]int, P)
	prevRemaider := -1 // We initialize prevRemaider variable as -1
	// We iterate through the string S from the last character to the first character
	for i := N - 1; i >= 0; i-- {
		// We get the digit from the string S at the current index i
		digit := int(S[i] - '0')
		// If prevRemaider is equal to -1, we get the remainder of the first digit by dividing it by P
		if prevRemaider == -1 {
			remainder := digit % P
		} else {
			// Otherwise, we get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then we get the remainder of the result by dividing it by P
			remainder := (((multiplier * digit) % P) + prevRemaider) % P
		}
		// If the remainder is equal to 0, we add 1 to the answer variable
		if remainder == 0 {
			answer++
		}
		// We get the count of the current remainder from the slice remainderLookup
		count := remainderLookup[remainder]
		// We add the count to the answer variable
		answer += count
		// We update the slice remainderLookup with the new count of the current remainder
		count++
		remainderLookup[remainder] = count
		// We update the multiplier variable as multiplier * 10 % P
		prevRemaider = remainder
		multiplier = (multiplier * 10) % P
	}
	return answer
}

// inputScanner type is a custom struct for reading input
type inputScanner struct {
	*bufio.Scanner
}

// We create a constructor function for inputScanner
func newInputScanner(enabledScanWords bool, sizeInKB int) *inputScanner {
	scanner := bufio.NewScanner(os.Stdin) // We create a new bufio.Scanner instance for reading input
	if enabledScanWords {
		scanner.Split(bufio.ScanWords) // We enable scanWords if it's true
	}
	capacity := sizeInKB * 1024 // We calculate the buffer size based on the given sizeInKB
	buf := make([]byte, capacity) // We create a new byte slice with the calculated buffer size
	scanner.Buffer(buf, capacity) // We set the buffer for the scanner instance
	return &inputScanner{ // We return a new inputScanner instance with the scanner instance as its field
		Scanner: scanner,
	}
}

// nextInt function reads an integer from the input and converts it to an integer
func (inputSc *inputScanner) nextInt() int {
	i, e := strconv.Atoi(inputSc.nextStr()) // We try to convert the next string to an integer
	if e != nil {
		panic(e) // If the conversion fails, we panic with the error
	}
	return i // If the conversion is successful, we return the integer
}

// nextUInt64 function reads an unsigned integer from the input and converts it to an unsigned integer
func (inputSc *inputScanner) nextUInt64() uint64 {
	i, e := strconv.ParseUint(inputSc.nextStr(), 10, 64) // We try to convert the next string to an unsigned integer
	if e != nil {
		panic(e) // If the conversion fails, we panic with the error
	}
	return i // If the conversion is successful, we return the unsigned integer
}

// nextStr function reads the next string from the input
func (inputSc *inputScanner) nextStr() string {
	inputSc.Scan() // We scan the next token from the input
	return inputSc.Text() // We return the scanned string
}
