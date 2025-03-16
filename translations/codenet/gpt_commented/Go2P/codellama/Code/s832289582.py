
# Go:
# package main

# import (
# 	"bufio"
# 	"fmt"
# 	"os"
# 	"strconv"
# )

# // N: [1, 2e5]
# // len(S) = N
# // P: [2, 10000], prime
# func main() {
# 	// Initialize the input scanner with a buffer size of 256 KB
# 	sc := newInputScanner(true, 256)
	
# 	// Read the integer values N and P, and the string S from input
# 	N, P, S := sc.nextInt(), sc.nextInt(), sc.nextStr()
	
# 	// Check the sub-numbers based on the conditions and print the result
# 	answer := checkSubNumbers(N, P, S)
# 	fmt.Println(answer)
# }

# // checkSubNumbers determines the method to check sub-numbers based on the value of P
# func checkSubNumbers(N int, P int, S string) int {
# 	switch P {
# 	case 2, 5:
# 		// If P is 2 or 5, use the specific check for these primes
# 		return checkTwoOrFive(N, P, S)
# 	default:
# 		// For other primes, use the general check
# 		return checkNotTwoNorFive(N, P, S)
# 	}
# }

# // checkTwoOrFive counts the sub-numbers divisible by 2 or 5
# func checkTwoOrFive(N int, P int, S string) int {
# 	answer := 0
# 	var n int
	
# 	// Iterate through the string S from the end to the beginning
# 	for i := N - 1; i >= 0; i-- {
# 		// Convert the character to an integer
# 		n, _ = strconv.Atoi(S[i : i+1])
		
# 		// Check if the digit is divisible by P and update the answer
# 		if n%P == 0 {
# 			answer += i + 1 // Count the number of valid sub-numbers
# 		}
# 	}
# 	return answer
# }

# // checkNotTwoNorFive counts the sub-numbers for primes other than 2 and 5
# func checkNotTwoNorFive(N int, P int, S string) int {
# 	multiplier := 1 // Initialize the multiplier for 10^i % P
# 	answer := 0     // Initialize the answer counter
# 	remainderLookup := make([]int, P) // Array to keep track of remainders
# 	prevRemaider := -1 // Variable to store the previous remainder
# 	var digit, remainder, count int
	
# 	// Iterate through the string S from the end to the beginning
# 	for i := N - 1; i >= 0; i-- {
# 		digit = int(S[i] - '0') // Convert the character to an integer
		
# 		// Calculate the current remainder based on the previous remainder
# 		if prevRemaider == -1 { // First digit case
# 			remainder = digit % P
# 		} else {
# 			remainder = (((multiplier * digit) % P) + prevRemaider) % P
# 		}
		
# 		// If the remainder is zero, increment the answer
# 		if remainder == 0 {
# 			answer++
# 		}
		
# 		// Update the count of sub-numbers with the current remainder
# 		count = remainderLookup[remainder]
# 		answer += count // Add the count of previous occurrences of this remainder
# 		count++ // Increment the count for this remainder
# 		remainderLookup[remainder] = count // Store the updated count
# 		prevRemaider = remainder // Update the previous remainder
# 		multiplier = (multiplier * 10) % P // Update the multiplier for the next digit
# 	}
# 	return answer
# }

# // inputScanner wraps bufio.Scanner for easier input handling
# type inputScanner struct {
# 	*bufio.Scanner
# }

# // newInputScanner initializes a new input scanner with a specified buffer size
# func newInputScanner(enabledScanWords bool, sizeInKB int) *inputScanner {
# 	scanner := bufio.NewScanner(os.Stdin)
# 	if enabledScanWords {
# 		scanner.Split(bufio.ScanWords) // Set the scanner to split input by words
# 	}
# 	capacity := sizeInKB * 1024 // Calculate the buffer capacity in bytes
# 	buf := make([]byte, capacity) // Create a buffer of the specified size
# 	scanner.Buffer(buf, capacity) // Set the buffer for the scanner
# 	return &inputScanner{
# 		Scanner: scanner,
# 	}
# }

# // nextInt reads the next integer from input
# func (inputSc *inputScanner) nextInt() int {
# 	i, e := strconv.Atoi(inputSc.nextStr()) // Convert the next string to an integer
# 	if e != nil {
# 		panic(e) // Panic if there is an error in conversion
# 	}
# 	return i // Return the integer value
# }

# // nextUInt64 reads the next uint64 from input
# func (inputSc *inputScanner) nextUInt64() uint64 {
# 	i, e := strconv.ParseUint(inputSc.nextStr(), 10, 64) // Convert the next string to uint64
# 	if e != nil {
# 		panic(e) // Panic if there is an error in conversion
# 	}
# 	return i // Return the uint64 value
# }

# // nextStr reads the next string from input
# func (inputSc *inputScanner) nextStr() string {
# 	inputSc.Scan() // Scan the next input
# 	return inputSc.Text() // Return the scanned text
# }

# 