package main

import (
	"fmt"
	"math"
)

func main() {
	var cookies [3]int
	for i := 0; i < 3; i++ {
		fmt.Scan(&cookies[i]) // Taking input from the user
	}

	leftOver := cookies[0] - cookies[2] // Calculating the difference between the first and third elements of the array
	takahashi := int(math.Max(0, float64(leftOver))) // Calculating the number of cookies Takahashi gets, ensuring it's not negative

	if takahashi > 0 {
		fmt.Printf("%d %d\n", takahashi, cookies[1]) // Printing the result when Takahashi gets cookies
	} else {
		fmt.Printf("%d %d\n", takahashi, int(math.Max(0, float64(cookies[1]-abs(leftOver))))) // Printing the result when Takahashi gets no cookies
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>
