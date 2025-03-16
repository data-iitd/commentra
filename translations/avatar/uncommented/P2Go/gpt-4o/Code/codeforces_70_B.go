package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans, sumL := 1, 0

	var input string
	fmt.Scan(&input)

	// Split the input string based on punctuation marks
	re := regexp.MustCompile(`[.?!]`)
	sentences := re.Split(input, -1)

	for _, s := range sentences {
		s = strings.TrimSpace(s) + "."
		L := len(s)
		if L > 1 {
			if L > n {
				fmt.Println("Impossible")
				return
			}
			if sumL+L+(sumL > 0) > n {
				ans++
				sumL = L
			} else {
				sumL = sumL + L + boolToInt(sumL > 0)
			}
		}
	}
	fmt.Println(ans)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

// <END-OF-CODE>
