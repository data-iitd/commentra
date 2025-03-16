package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare static members for output stream and print writer
var outputStream = os.Stdout
var out = bufio.NewWriter(outputStream)

func main() {
	// Read the number of test cases
	var t, n, in int
	fmt.Fscan(os.Stdin, &t)

	// Initialize priority queues for max and min values
	pqmax := make([]int, 0)
	pqmin := make([]int, 0)

	// Initialize variables to keep track of sums and the minimum value
	var sumMin, sumMax, sumb, min int64

	// Process each test case
	for t > 0 {
		// Read the input for the current test case
		var s string
		fmt.Fscan(os.Stdin, &s)
		s = strings.Split(s, " ")[0]

		// If the command is '2', calculate and print the result
		if s[0] == '2' {
			ans := min
			ans *= int(len(pqmin))
			ans -= sumMin
			ans1 := min
			ans1 *= int(len(pqmax))
			ans1 = sumMax - ans1
			fmt.Fprintln(out, min, " ", ans+ans1+sumb)
		}
		// If the command is '1', add the new value to the appropriate priority queue
		else {
			fmt.Fscan(os.Stdin, &in, &n)
			sumb += int64(n)

			if in > min {
				pqmax = append(pqmax, in)
				sumMax += int64(in)
			} else {
				pqmin = append(pqmin, in)
				sumMin += int64(in)
			}

			// Balance the priority queues
			if len(pqmin) > len(pqmax) {
				sumMax += int64(pqmin[0])
				sumMin -= int64(pqmin[0])
				pqmax = append(pqmax, pqmin[0])
				pqmin = pqmin[1:]
			}

			if len(pqmin) < len(pqmax) {
				sumMax -= int64(pqmax[0])
				sumMin += int64(pqmax[0])
				pqmin = append(pqmin, pqmax[0])
				pqmax = pqmax[1:]
			}

			// Update the minimum value
			min = pqmin[0]
		}
		t--
	}

	// Close the print writer to flush the output
	out.Flush()
}

