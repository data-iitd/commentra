package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of test cases

	// Allocating an array of size 'n' to store characters
	ch := make([]rune, n)
	var s1, s2 int
	var i, j int
	var flag int

	// Reading input for each test case
	for i = 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Reading the value of 'x' and 'y' for the current test case

		temp1 := s1 + x
		temp2 := s2 + y

		// Checking if the difference between the sums is within the limit of 500
		if math.Abs(float64(temp1-temp2)) <= 500 {
			s1 += x
			ch[j] = 'A'
			j++
			continue
		}

		// Checking if the difference between the absolute values of the sums is within the limit of 500
		if math.Abs(float64(temp1-s2)) <= 500 {
			s2 += y
			ch[j] = 'G'
			j++
			continue
		}

		flag = 1
		break
	}

	// Checking if the flag is set to 1, indicating that the difference between the sums is greater than 500 for the current test case
	if flag == 1 {
		fmt.Println(-1)
	} else {
		ans := string(ch[:j]) // Converting the character array 'ch' to a string 'ans'
		fmt.Println(ans)      // Printing the string 'ans' as the answer for the current test case
	}
}
