
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Define input variables
	var N, K int
	var S string
	// Initialize a flag variable
	aaaa := false
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the first line of input, which contains two integers N and K
	scanner.Scan()
	// Split the line into two integers and assign them to N and K
	N, _ = strconv.Atoi(scanner.Text()[0:1])
	K, _ = strconv.Atoi(scanner.Text()[2:3])
	// Read the second line of input, which contains a string S
	scanner.Scan()
	S = scanner.Text()
	// Check if K is greater than or equal to 15
	if K >= 15 {
		// If so, set the flag variable to True
		aaaa = true
	}
	// Else, check if 2^K is greater than or equal to N
	else if 2**K >= N {
		// If so, set the flag variable to True
		aaaa = true
	}
	// If the flag variable is True, print the result and exit the function
	if aaaa {
		fmt.Println(string(S[0]) * N)
		return
	}
	// Define a function to get the last dictionary of the string S
	func get_last_dict(s string) string {
		// Create a new string U by concatenating S with its reverse
		U := s + reverse(s)
		// Find the minimum character in S
		c := string(s[0])
		// Find the index of the first occurrence of the minimum character in U
		p := index(U, c)
		// Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
		minindex := p
		// Move the pointer p to the next character in U
		p += 1
		// Check if the substring starting from the current pointer and of length N is a normal dictionary
		for p <= N {
			// If the character at the current pointer in U is the same as the minimum character,
			// and if the substring starting from the current pointer and of length N is a normal dictionary,
			// update the index minindex
			if string(U[p]) == c && check_normal_dict(U, minindex, p) {
				minindex = p
			}
			// Move the pointer p to the next character in U
			p += 1
		}
		// Return the substring starting from minindex and of length N
		return U[minindex : minindex+N]
	}
	// Define a function to check if a substring is a normal dictionary
	func check_normal_dict(u string, pointer1 int, pointer2 int) bool {
		// Iterate through each character in the substring of length N
		for i := 0; i < N; i++ {
			// If the character at pointer1+i in U is greater than the character at pointer2+i,
			// return True (indicating that the substring is a normal dictionary)
			if u[pointer1+i] > u[pointer2+i] {
				return true
			}
			// Else, if the character at pointer1+i is less than the character at pointer2+i,
			// return False (indicating that the substring is not a normal dictionary)
			if u[pointer1+i] < u[pointer2+i] {
				return false
			}
		}
		// If none of the above conditions are met, return False
		return false
	}
	// Define a function to reverse a string
	func reverse(s string) string {
		// Create a new string to store the reversed string
		r := ""
		// Iterate through each character in the input string in reverse order
		for i := len(s) - 1; i >= 0; i-- {
			// Append the current character to the reversed string
			r += string(s[i])
		}
		// Return the reversed string
		return r
	}
	// Define a function to find the index of a character in a string
	func index(s string, c string) int {
		// Iterate through each character in the input string
		for i := 0; i < len(s); i++ {
			// If the current character is the same as the target character,
			// return the index of the current character
			if string(s[i]) == c {
				return i
			}
		}
		// If none of the above conditions are met, return -1
		return -1
	}
	// Get the last dictionary of the string S
	S = get_last_dict(S)
	// If K is equal to 1, print the string S
	if K == 1 {
		fmt.Println(S)
	}
	// Else, check if the number of occurrences of the first character in S is greater than or equal to N/2^(K-1)
	else {
		count := 0
		for i := 0; i < len(S); i++ {
			// If the current character is the same as the first character, increment the count
			if string(S[i]) == string(S[0]) {
				count += 1
			}
			// Else, break the loop
			else {
				break
			}
		}
		// If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
		if count*(2**(K-1)) >= N {
			fmt.Println(string(S[0]) * N)
		}
		// Else, construct the string S by concatenating N-1 instances of the first character with the original string S
		else {
			S = string(S[0])*(count*(2**(K-1))-1) + S
			// Print the first N characters of the constructed string S
			fmt.Println(S[:N])
		}
	}
}

