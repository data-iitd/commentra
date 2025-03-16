package main

import (
	"fmt"
	"math"
)

func main() {
	// Taking input for N and S
	var N int
	fmt.Scanf("%d", &N)
	var S string
	fmt.Scanf("%s", &S)

	// Defining the function calculate that takes two parameters, n and s
	func calculate(n int, s string) {
		// Converting the string s into a list of characters
		arr := []rune(s)

		// Calculating the counts of 'R', 'G', and 'B'
		rNum := 0
		gNum := 0
		bNum := 0
		for _, v := range arr {
			if v == 'R' {
				rNum++
			} else if v == 'G' {
				gNum++
			} else if v == 'B' {
				bNum++
			}
		}

		// Initializing sum to 0
		sum := 0

		// Iterating over possible step sizes from 1 to math.Ceil(n / 2) + 1
		for step := 1; step <= int(math.Ceil(float64(n)/2))+1; step++ {
			// Iterating over possible starting indices for the substring
			for i := 0; i < n-2*step; i++ {
				// Forming a substring of length 3
				s := string(arr[i]) + string(arr[i+step]) + string(arr[i+step*2])

				// Checking if the substring matches any of the patterns
				if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
					sum++
				}
			}
		}

		// Printing the product of the counts of 'R', 'G', and 'B' minus sum
		fmt.Printf("%d\n", rNum*gNum*bNum-sum)
	}

	// Calling the function calculate with N and S as arguments
	calculate(N, S)
}

