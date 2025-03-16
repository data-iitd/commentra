package main

import (
	"fmt"
)

func main() {
	var m, f, r int
	for {
		_, err := fmt.Scan(&m, &f, &r)
		if err != nil || (m == -1 && f == -1 && r == -1) {
			break // Exit the loop if input fails or all values are -1
		}
		if m == -1 || f == -1 {
			fmt.Println("F") // Output "F" if any of m or f is -1
		} else if m+f >= 80 {
			fmt.Println("A") // Output "A" if the sum of m and f is 80 or more
		} else if m+f >= 65 {
			fmt.Println("B") // Output "B" if the sum of m and f is 65 or more
		} else if m+f >= 50 || r >= 50 {
			fmt.Println("C") // Output "C" if the sum of m and f is 50 or more, or r is 50 or more
		} else if m+f >= 30 {
			fmt.Println("D") // Output "D" if the sum of m and f is 30 or more
		} else {
			fmt.Println("F") // Output "F" if none of the above conditions are met
		}
	}
}

// <END-OF-CODE>
