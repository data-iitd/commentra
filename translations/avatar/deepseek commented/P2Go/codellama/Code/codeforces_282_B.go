
package main

import "fmt"

func main() {
	var firstline int
	fmt.Scan(&firstline)
	var total int
	var memory []string

	for x := 0; x < firstline; x++ {
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

	fmt.Println(memory)
}

