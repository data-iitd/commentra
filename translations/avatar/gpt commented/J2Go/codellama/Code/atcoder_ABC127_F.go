package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// BufferedReader to read input from standard input
	br := bufio.NewReader(os.Stdin)

	// Read the number of test cases
	t, _ := strconv.Atoi(br.ReadString('\n'))

	// Arrays and priority queues for processing input
	s := make([]string, 0)
	pqmax := make([]int, 0) // Min-heap for maximum values
	pqmin := make([]int, 0) // Max-heap for minimum values

	// Variables to store sums and minimum value
	sumMin := 0
	sumMax := 0
	sumb := 0
	min := 0

	// Process each test case
	for t > 0 {
		// Read the input line and split it into parts
		s = strings.Split(br.ReadString('\n'), " ")

		// If the first character is '2', calculate and print the result
		if s[0][0] == '2' {
			ans := min
			ans *= len(pqmin)
			ans -= sumMin
			ans1 := min
			ans1 *= len(pqmax)
			ans1 = sumMax - ans1

			// Print the minimum value and the calculated result
			fmt.Println(min, ans+ans1+sumb)
		} else {
			// Parse the input values
			in, _ := strconv.Atoi(s[1])
			sumb += in

			// Add the input value to the appropriate priority queue
			if in > min {
				pqmax = append(pqmax, in)
				sumMax += in
			} else {
				pqmin = append(pqmin, in)
				sumMin += in
			}

			// Balance the two heaps if necessary
			if len(pqmin) > len(pqmax) {
				sumMax += pqmin[0]
				sumMin -= pqmin[0]
				pqmax = append(pqmax, pqmin[0])
				pqmin = pqmin[1:]
			}
			if len(pqmin) < len(pqmax) {
				sumMax -= pqmax[0]
				sumMin += pqmax[0]
				pqmin = append(pqmin, pqmax[0])
				pqmax = pqmax[1:]
			}

			// Update the minimum value based on the current state of the heaps
			min = pqmin[0]
		}

		t--
	}
}

