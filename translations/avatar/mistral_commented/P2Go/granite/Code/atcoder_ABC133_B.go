
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initializing a variable'reader' to read input from the standard input
	reader := bufio.NewReader(os.Stdin)

	// Taking the number of points, n, and the number of dimensions, d, as input
	n, d := readTwoInt64s(reader)

	// Initializing a 2D slice 'points' of size 'n'x'd' to store the coordinates of each point
	points := make([][]int64, n)
	for i := 0; i < n; i++ {
		points[i] = readNInt64s(reader, d)
	}

	// Defining a function 'dist' to calculate the Euclidean distance between two points
	dist := func(x, y []int64) float64 {
		// Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
		tmp := 0.0

		// Iterating through each dimension 'i' from 0 to 'd'
		for i := 0; i < d; i++ {
			// Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
			tmp += math.Pow(float64(x[i]-y[i]), 2)
		}

		// Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
		return math.Sqrt(tmp)
	}

	// Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
	count := 0

	// Iterating through each point 'i' in 'points'
	for i := 0; i < n; i++ {
		// Iterating through each point 'j' from 'i+1' to the last point in 'points'
		for j := i + 1; j < n; j++ {
			// Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
			if dist(points[i], points[j]).IsInt() {
				// Incrementing the 'count' variable if the condition is true
				count++
			}
		}
	}

	// Printing the final value of 'count'
	fmt.Println(count)
}

// Function to read an integer from the standard input
func readInt(reader *bufio.Reader) int {
	// Initializing a variable'res' to store the integer value read from the input
	res := 0
	// Initializing a variable'sign' to store the sign of the integer value
	sign := 1
	// Reading a byte from the input
	char, _, err := reader.ReadByte()
	if err!= nil {
		panic(err)
	}
	// Checking if the byte is a minus sign
	if char == '-' {
		// Setting the'sign' variable to -1 if the byte is a minus sign
		sign = -1
		// Reading a byte from the input again
		char, _, err = reader.ReadByte()
		if err!= nil {
			panic(err)
		}
	}
	// Converting the byte to an integer and multiplying it by the'sign' variable to get the final integer value
	res = int(char - '0') * sign
	// Reading the remaining bytes from the input until a whitespace character is encountered
	for char, _, err = reader.ReadByte(); err == nil && char!=''; char, _, err = reader.ReadByte() {
		res *= 10
		res += int(char - '0')
	}
	// Returning the final integer value
	return res
}

// Function to read an integer64 from the standard input
func readInt64(reader *bufio.Reader) int64 {
	// Initializing a variable'res' to store the integer64 value read from the input
	res := int64(0)
	// Initializing a variable'sign' to store the sign of the integer64 value
	sign := int64(1)
	// Reading a byte from the input
	char, _, err := reader.ReadByte()
	if err!= nil {
		panic(err)
	}
	// Checking if the byte is a minus sign
	if char == '-' {
		// Setting the'sign' variable to -1 if the byte is a minus sign
		sign = -1
		// Reading a byte from the input again
		char, _, err = reader.ReadByte()
		if err!= nil {
			panic(err)
		}
	}
	// Converting the byte to an integer64 and multiplying it by the'sign' variable to get the final integer64 value
	res = int64(char - '0') * sign
	// Reading the remaining bytes from the input until a whitespace character is encountered
	for char, _, err = reader.ReadByte(); err == nil && char!=''; char, _, err = reader.ReadByte() {
		res *= 10
		res += int64(char - '0')
	}
	// Returning the final integer64 value
	return res
}

// Function to read an array of integers from the standard input
func readNInt64s(reader *bufio.Reader, n int) []int64 {
	// Initializing a slice'res' to store the array of integers
	res := make([]int64, n)
	// Iterating through each index 'i' from 0 to 'n-1'
	for i := 0; i < n; i++ {
		// Reading an integer64 from the input and storing it in the 'i'th index of'res'
		res[i] = readInt64(reader)
	}
	// Returning the final array of integers
	return res
}

// Function to read two integers from the standard input
func readTwoInt64s(reader *bufio.Reader) (int64, int64) {
	// Initializing two variables 'a' and 'b' to store the two integers read from the input
	a, b := int64(0), int64(0)
	// Reading an integer64 from the input and storing it in the variable 'a'
	a = readInt64(reader)
	// Reading another integer64 from the input and storing it in the variable 'b'
	b = readInt64(reader)
	// Returning the two integers as a tuple
	return a, b
}

// Function to read a string from the standard input
func readString(reader *bufio.Reader) string {
	// Initializing a variable'res' to store the string read from the input
	res := ""
	// Reading a byte from the input until a whitespace character is encountered
	for char, _, err := reader.ReadByte(); err == nil && char!=''; char, _, err = reader.ReadByte() {
		res += string(char)
	}
	// Returning the final string
	return res
}

// Function to read an array of strings from the standard input
func readNStrings(reader *bufio.Reader, n int) []string {
	// Initializing a slice'res' to store the array of strings
	res := make([]string, n)
	// Iterating through each index 'i' from 0 to 'n-1'
	for i := 0; i < n; i++ {
		// Reading a string from the input and storing it in the 'i'th index of'res'
		res[i] = readString(reader)
	}
	// Returning the final array of strings
	return res
}

// Function to read a grid of characters from the standard input
func readGrid(reader *bufio.Reader, n int, m int) [][]byte {
	// Initializing a 2D slice'res' to store the grid of characters
	res := make([][]byte, n)
	// Iterating through each row 'i' from 0 to 'n-1'
	for i := 0; i < n; i++ {
		// Reading a line of characters from the input and storing it in the 'i'th row of'res'
		res[i] = []byte(readString(reader))
	}
	// Returning the final grid of characters
	return res
}

// Function to check if a float64 value is an integer
func (f float64) IsInt() bool {
	// Converting the float64 value to an integer and checking if it is equal to the float64 value
	return f == float64(int(f))
}

// Function to check if a string is a palindrome
func isPalindrome(s string) bool {
	// Initializing two variables 'left' and 'right' to keep track of the left and right indices of the string
	left, right := 0, len(s)-1
	// Iterating through the string until the 'left' index is less than the 'right' index
	for left < right {
		// Checking if the characters at the 'left' and 'right' indices are not equal
		if s[left]!= s[right] {
			// Returning false if the characters are not equal
			return false
		}
		// Incrementing the 'left' index and decrementing the 'right' index
		left++
		right--
	}
	// Returning true if the string is a palindrome
	return true
}

// Function to check if a string is a palindrome
func isPalindrome2(s string) bool {
	// Initializing a variable 'left' to keep track of the left index of the string
	left := 0
	// Iterating through the string until the 'left' index is less than half the length of the string
	for left < len(s)/2 {
		// Checking if the characters at the 'left' and 'right' indices are not equal
		if s[left]!= s[len(s)-1-left] {
			// Returning false if the characters are not equal
			return false
		}
		// Incrementing the 'left' index
		left++
	}
	// Returning true if the string is a palindrome
	return true
}

// Function to check if a string is a palindrome
func isPalindrome3(s string) bool {
	// Initializing a variable 'left' to keep track of the left index of the string
	left := 0
	// Iterating through the string until the 'left' index is less than half the length of the string
	for left < len(s)/2 {
		// Checking if the characters at the 'left' and 'right' indices are not equal
		if s[left]!= s[len(s)-1-left] {
			// Returning false if the characters are not equal
			return false
		}
		// Incrementing the 'left' index
		left++
	}
	// Returning true if the string is a palindrome
	return true
}

// Function to check if a string is a palindrome
func isPalindrome4(s string) bool {
	// Initializing a variable 'left' to keep track of the left index of the string
	left := 0
	// Iterating through the string until the 'left' index is less than half the length of the string
	for left < len(s)/2 {
		// Checking if the characters at the 'left' and 'right' indices are not equal
		if s[left]!= s[len(s)-1-left] {
			// Returning false if the characters are not equal
			return false
		}
		// Incrementing the 'left' index
		left++
	}
	// Returning true if the string is a palindrome
	return true
}

// Function to check if a string is a palindrome
func isPalindrome5(s string) bool {
	// Initializing a variable 'left' to keep track of the left index of the string
	left := 0
	// Iterating through the string until the 'left' index is less than half the length of the string
	for left < len(s)/2 {
		// Checking if the characters at the 'left' and 'right' indices are not equal
		if s[left]!= s[len(s)-1-left] {
			// Returning false if the characters are not equal
			return false
		}
		// Incrementing the 'left' index
		left++
	}
	// Returning true if the string is a palindrome
	return true
}

// Function to check if a string is a palindrome
func isPalindrome6(s string) bool {
	// Initializing a variable 'left' to keep track of the left index of the string
	left := 0
	// Iterating through the string until the 'left' index is less than half the length of the string
	for left < len(s)/2 {
		// Checking if the characters at the 'left' and 'right' indices are not equal
		if s[left]!= s[len(s)-1-left] {
			// Returning false if the characters are not equal
			return false
		}
		// Incrementing the 'left' index
		left++
	}
	// Returning true if the string is a palindrome
	return true