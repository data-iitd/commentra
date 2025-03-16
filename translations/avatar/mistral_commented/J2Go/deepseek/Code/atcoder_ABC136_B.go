package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	count := 0
	temp := N

	// The following while loop calculates the number of digits in the given integer 'N'
	for temp > 0 {
		temp /= 10
		count++
	}

	ans := 0

	// The following for loop iterates through each digit of the given integer 'N'
	for i := 1; i <= count; i++ {
		if i == count {
			// If the last digit is odd
			if i%2 == 1 {
				ans += (N - int(math.Pow(10, float64(i-1))) + 1)
			}
		} else {
			if i == 1 {
				// If the first digit
				ans += 9
			} else if i%2 == 1 {
				// If the current digit is odd
				ans += int(math.Pow(10, float64(i)) - math.Pow(10, float64(i-1)))
			}
		}
	}

	fmt.Println(ans)
}

