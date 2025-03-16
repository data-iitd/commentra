package main

import "fmt"

func main() {
	// 1. Define the array and variables
	su := make([]byte, 1000)
	susum := 0
	j := 0

	for {
		// 2. Read input and calculate sum
		for j = 0; j < 1000; j++ {
			fmt.Scanf("%c", &su[j])
			if su[j] == '\n' {
				break
			}
			susum += int(su[j] - '0')
		}
		if su[0] == '0' {
			break
		}
		// 3. Print the sum
		fmt.Printf("%d\n", susum)
		susum = 0
	}
	// 4. Check for termination condition
	// 