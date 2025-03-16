package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var str string
	fmt.Scan(&str)

	// Constructing the string a by taking the first n/2 characters of str
	a := ""
	for i := 0; i < n/2; i++ {
		a += string(str[i])
	}

	// Checking if str is equal to a + a and printing the result
	if str == a+a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
