<<<<<<< HEAD

import (
    "fmt"
    "math"
=======
package main

import (
	"fmt"
	"math"
>>>>>>> 98c87cb78a (data updated)
)

// Define constants and variables
var (
<<<<<<< HEAD
    ans, mx, sum, mn = 1e8, 1, 1, 1e8
    cnt = 1
)

func main() {
    // Input the value of h
    var h int
    fmt.Scanf("%d", &h)

    // Loop to calculate the answer
    for h!= 1 {
        if h%2!= 0 {
            h--
        }
        h /= 2
        cnt *= 2
        ans += cnt
    }

    // Output the final result
    fmt.Printf("%d\n", ans+1)
=======
	ans, mx, sum, mn = 1e8, 1, 1, 1e8
	cnt               = 1
)

func main() {
	// Input the value of h
	var h int
	fmt.Scanf("%d", &h)

	// Loop to calculate the answer
	for h!= 1 {
		if h%2!= 0 {
			h-- // Decrement h if it is odd
		}
		h /= 2 // Divide h by 2
		cnt *= 2 // Double the count
		ans += cnt // Increment the sum by the current count
	}

	// Output the final result
	fmt.Printf("%d\n", ans+1)
>>>>>>> 98c87cb78a (data updated)
}

