package main

import (
	"fmt"
	"strings"
)

func main() {
	var firstline int
	fmt.Scan(&firstline)

	total := 0
	memory := []string{}

	for i := 0; i < firstline; i++ {
		var A, G int
		fmt.Scan(&A, &G)

		if total+A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}

	fmt.Println(strings.Join(memory, ""))
}

// <END-OF-CODE>
