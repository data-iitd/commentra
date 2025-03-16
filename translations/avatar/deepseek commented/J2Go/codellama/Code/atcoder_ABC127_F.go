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
	// Initialize BufferedReader to read input from System.in
	br := bufio.NewReader(os.Stdin)

	// Read the number of test cases
	t, _ := strconv.Atoi(br.ReadString('\n'))

	// Initialize priority queues for max and min values
	pqmax := make([]int, 0)
	pqmin := make([]int, 0)

	// Initialize variables to keep track of sums and the minimum value
	sumMin := 0
	sumMax := 0
	sumb := 0
	min := 0

	// Process each test case
	for t > 0 {
		// Read the input for the current test case
		s := strings.Split(br.ReadString('\n'), " ")

		// If the command is '2', calculate and print the result
		if s[0] == "2" {
			ans := min
			ans *= len(pqmin)
			ans -= sumMin
			ans1 := min
			ans1 *= len(pqmax)
			ans1 = sumMax - ans1
			fmt.Println(min, ans+ans1+sumb)
		} else {
			// If the command is '1', add the new value to the appropriate priority queue
			in, _ := strconv.Atoi(s[1])
			sumb += in

			if in > min {
				pqmax = append(pqmax, in)
				sumMax += in
			} else {
				pqmin = append(pqmin, in)
				sumMin += in
			}

			// Balance the priority queues
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

			// Update the minimum value
			min = pqmin[0]
		}

		t--
	}
}

