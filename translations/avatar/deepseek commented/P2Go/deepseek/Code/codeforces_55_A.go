package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)  // Take an integer input from the user
	for n%2 == 0 {  // Check if the number is even and keep dividing by 2 until odd
		n /= 2
	}
	if n == 1 {  // Check if the number has been reduced to 1
		fmt.Println("YES")  // Print 'YES' if the original number was a power of 2
	} else {
		fmt.Println("NO")  // Print 'NO' if the original number was not a power of 2
	}
}

