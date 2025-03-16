package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B) // Taking two integer inputs A and B
	ans := A - 2*B   // Calculating the value of ans as A minus two times B
	if ans < 0 {     // Checking if ans is less than 0
		ans = 0      // Setting ans to 0 if it is less than 0
	}
	fmt.Println(ans) // Printing the value of ans
}

// <END-OF-CODE>
