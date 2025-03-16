
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two long integers from the input
	var l, r int64
	fmt.Scanf("%d %d", &l, &r)

	// Calculate the maximum product for each range and store it in the array maxxes
	maxxes := make([]int64, 10)
	for i := 0; i < 10; i++ {
		maxxes[i] = int64(math.Pow(10, float64(i+1))) - 1
	}

	// Calculate the maximum product for the given ranges and update the result res
	res := int64(0)
	res = int64(math.Max(float64(res), float64(l*r)))
	res = int64(math.Max(float64(res), float64(l*maxxes[0])))
	res = int64(math.Max(float64(res), float64(r*maxxes[9])))

	// Check if the middle value of the range is within the given range and update the result res accordingly
	for i := 0; i < 10; i++ {
		if l <= maxxes[i]/2 && maxxes[i]/2 <= r {
			res = int64(math.Max(float64(res), float64(maxxes[i])))
		}
	}

	// Print the final result
	fmt.Printf("%d\n", res)
}

