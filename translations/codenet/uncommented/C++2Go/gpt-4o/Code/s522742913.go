package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var source string
	fmt.Scan(&source)

	if len(source) > 10 || len(source) < 1 {
		return
	}

	maxI := int(math.Pow(2, float64(len(source)-1)))
	sum := 0.0

	for i := 0; i < maxI; i++ {
		plus := fmt.Sprintf("%b", i)
		plus = fmt.Sprintf("%0*s", len(source)-1, plus) // Pad with leading zeros

		number := 0.0
		working := source

		for j := 0; j < len(plus); j++ {
			if plus[j] == '1' {
				if j == 0 {
					// If it's the first character, take the whole substring
					number, _ = strconv.ParseFloat(working, 64)
					sum += number
					break
				} else {
					// Take the substring up to the current index
					numStr := working[:j+1]
					number, _ = strconv.ParseFloat(numStr, 64)
					sum += number
					working = working[j+1:]
				}
			}
		}
		// Add the remaining part of the string
		if len(working) > 0 {
			number, _ = strconv.ParseFloat(working, 64)
			sum += number
		}
	}

	fmt.Printf("%.0f\n", sum)
}

// <END-OF-CODE>
