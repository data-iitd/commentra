package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n int
	var ch []rune
	var s1, s2 int
	var i, j, flag, dif int
	var temp1, temp2 int

	// Read the number of elements
	n, _ = strconv.Atoi(os.Args[1])
	ch = make([]rune, n)
	s1 = 0
	s2 = 0
	flag = 0
	dif = 0

	// Loop to read inputs and decide paths
	for i = 0; i < n; i++ {
		// Read the next integer for path 'x'
		x, _ := strconv.Atoi(os.Args[2*i+2])
		// Read the next integer for path 'y'
		y, _ := strconv.Atoi(os.Args[2*i+3])
		temp1 = s1 + x
		temp2 = s2 + y

		// Check if adding to path 'x' or 'y' is valid
		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x
			ch[j] = 'A'
			j++
			continue
		}
		if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y
			ch[j] = 'G'
			j++
			continue
		}
		flag = 1
		break
	}

	// Handle the result based on the flag
	if flag == 1 {
		fmt.Println(-1)
	} else {
		ans := string(ch)
		fmt.Println(ans)
	}
}

