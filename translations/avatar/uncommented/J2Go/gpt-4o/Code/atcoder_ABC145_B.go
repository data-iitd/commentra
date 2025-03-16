package main

import (
	"fmt"
)

func main() {
	var n int
	var str string

	fmt.Scan(&n)
	fmt.Scan(&str)

	a := ""
	for i := 0; i < n/2; i++ {
		a += string(str[i])
	}

	if str == a+a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
