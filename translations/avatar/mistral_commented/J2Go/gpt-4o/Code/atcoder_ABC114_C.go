package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N) // Getting the value of N from user input

	i := int64(357) // Initializing the variable i with a value of 357
	c := 0          // Initializing the variable c with a value of 0

	for i <= int64(N) { // Starting a for loop that continues as long as i is less than or equal to N
		s := strconv.FormatInt(i, 10) // Converting the integer value of i to a string

		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") { // Checking if the string contains the digits 3, 5, and 7
			c++ // Incrementing the value of c by 1 if the condition is true
		}

		var sb strings.Builder // Creating a new strings.Builder object
		f := false            // Initializing a boolean variable f with a value of false

		for j := len(s) - 1; j >= 0; j-- { // Starting a for loop that iterates through each character in the string s in reverse order
			a := s[j] // Getting the character at the current index

			if f { // If the boolean variable f is true, meaning we have found the first occurrence of 3, 5, or 7
				sb.WriteByte(a) // Appending the current character to the strings.Builder object
			} else { // If the boolean variable f is false
				if a == '3' { // Checking if the current character is a 3
					sb.WriteByte('5') // If it is, append a 5 to the strings.Builder object and set f to true
					f = true
				} else if a == '5' { // Checking if the current character is a 5
					sb.WriteByte('7') // If it is, append a 7 to the strings.Builder object and set f to true
					f = true
				} else { // If the current character is not a 3, 5, or 7, append a 3 to the strings.Builder object and set f to true
					sb.WriteByte('3')
					f = true
				}
			}
		}

		if !f {
			sb.WriteByte('3') // If we have not found any 3, 5, or 7 in the string, append a 3 to the strings.Builder object
		}

		reversed := sb.String() // Get the string from the builder
		i, _ = strconv.ParseInt(reverseString(reversed), 10, 64) // Converting the reversed string back to a long integer and assigning it to the variable i
	}

	fmt.Println(c) // Printing the value of c to the console
}

func reverseString(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
