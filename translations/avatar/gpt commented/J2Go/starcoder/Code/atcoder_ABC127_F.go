package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Output stream for printing results
var outputStream = os.Stdout
var out = bufio.NewWriter(outputStream)

func main() {
	// Read the number of test cases
	t, _ := strconv.Atoi(readLine())

	// Arrays and priority queues for processing input
	var s []string
	pqmax := make(PriorityQueue, 0) // Min-heap for maximum values
	pqmin := make(PriorityQueue, 0) // Max-heap for minimum values

	// Variables to store sums and minimum value
	var sumMin, sumMax, sumb int64
	var min int

	// Process each test case
	for t > 0 {
		// Read the input line and split it into parts
		s = strings.Split(readLine(), " ")

		// If the first character is '2', calculate and print the result
		if s[0][0] == '2' {
			ans := min
			ans *= int64(len(pqmin))
			ans -= sumMin
			ans1 := min
			ans1 *= int64(len(pqmax))
			ans1 = sumMax - ans1

			// Print the minimum value and the calculated result
			fmt.Fprintln(out, min, " ", ans+ans1+sumb)
		} else {
			// Parse the input values
			in, _ := strconv.Atoi(s[1])
			sumb += int64(in) // Update the sum of additional values

			// Add the input value to the appropriate priority queue
			if in > min {
				pqmax = append(pqmax, in)
				sumMax += int64(in)
			} else {
				pqmin = append(pqmin, in)
				sumMin += int64(in)
			}

			// Balance the two heaps if necessary
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

			// Update the minimum value based on the current state of the heaps
			min = pqmin[0]
		}
		t--
	}

	// Close the output stream
	out.Flush()
}

// Read a line from input stream.
func readLine() string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := inputStream.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

// PriorityQueue implements a priority queue.
type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool { return pq[i] < pq[j] }

func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

