
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// BufferedReader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of test cases
	t, _ := strconv.Atoi(reader.ReadLine())

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
		s, _ = reader.ReadString('\n')
		s = strings.Split(s, " ")

		// If the first character is '2', calculate and print the result
		if s[0][0] == '2' {
			ans := int64(min) * int64(len(pqmin))
			ans -= sumMin
			ans1 := int64(min) * int64(len(pqmax))
			ans1 = sumMax - ans1
			fmt.Println(min, ans+ans1+sumb)
		} else {
			// Parse the input values
			in, _ := strconv.Atoi(s[1])
			sumb += int64(in)

			// Add the input value to the appropriate priority queue
			if in > min {
				pqmax = append(pqmax, in)
				sumMax += int64(in)
			} else {
				pqmin = append(pqmin, in)
				sumMin += int64(in)
			}

			// Balance the two heaps if necessary
			for len(pqmin) > len(pqmax)+1 {
				sumMax += int64(pqmin[0])
				sumMin -= int64(pqmin[0])
				pqmax = append(pqmax, pqmin[0])
				pqmin = pqmin[1:]
			}
			for len(pqmax) > len(pqmin) {
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
}

// PriorityQueue is a min-heap implementation
type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(int)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// Translate the above Go code to C++ and end with comment "