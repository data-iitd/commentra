package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input) // Taking an input from the user

	parts := strings.Split(input, ".") // Splitting the input into a slice of strings separated by a period (.)
	s := parts[0]                       // First part of the split input
	p := parts[1]                       // Second part of the split input
	i, _ := strconv.Atoi(string(p[0]))  // Converting the first character of the second part into an integer

	// Checking if the last character of the first part is '9'
	if s[len(s)-1] == '9' {
		fmt.Println("GOTO Vasilisa.") // Printing "GOTO Vasilisa." if the last character is '9'
	} else if s[len(s)-1] != '9' && i < 5 {
		fmt.Println(s) // Printing the first part if the last character is not '9' and the integer is less than 5
	} else {
		num, _ := strconv.Atoi(s) // Converting the first part into an integer
		num++                      // Incrementing the first part by 1
		fmt.Println(num)          // Printing the incremented number
	}
}

// <END-OF-CODE>
