package main

import (
	"fmt"
	"math"
)

func main() {
	var cookies [3]int

	// Read input and populate the cookies array
	for i := 0; i < 3; i++ {
		fmt.Scan(&cookies[i])
	}

	// Calculate the difference between the number of cookies given to the first and second child
	leftOver := cookies[0] - cookies[2]

	// Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
	takahashi := int(math.Max(0, float64(leftOver)))

	// Print the result using string concatenation
	if takahashi > 0 {
		fmt.Printf("%d %d\n", takahashi, cookies[1])
	} else {
		fmt.Printf("%d %d\n", takahashi, int(math.Max(0, float64(cookies[1]-int(math.Abs(float64(leftOver)))))))
	}
}

// <END-OF-CODE>
