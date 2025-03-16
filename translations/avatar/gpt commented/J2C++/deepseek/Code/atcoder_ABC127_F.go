package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Output stream for printing results
	outputStream := os.Stdout
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	// BufferedReader to read input from standard input
	br := bufio.NewReader(os.Stdin)

	// Read the number of test cases
	var t int
	fmt.Fscan(br, &t)

	// Arrays and priority queues for processing input
	var s []string
	pqmax := &PriorityQueue{less: func(i, j int) bool { return s[i] < s[j] }}
	pqmin := &PriorityQueue{less: func(i, j int) bool { return s[i] > s[j] }}

	// Variables to store sums and minimum value
	var sumMin, sumMax, sumb int64
	var min int

	// Process each test case
	for t > 0 {
		t--

		// Read the input line and split it into parts
		s, _ = bufio.NewReader(br).ReadString('\n')
		parts := strings.Split(s, " ")

		// If the first character is '2', calculate and print the result
		if parts[0][0] == '2' {
			ans := int64(min)
			ans *= int64(pqmin.Len())
			ans -= sumMin
			ans1 := int64(min)
			ans1 *= int64(pqmax.Len())
			ans1 = sumMax - ans1

			// Print the minimum value and the calculated result
			fmt.Fprintln(out, min, ans+ans1+sumb)
		} else {
			// Parse the input values
			in, _ := strconv.Atoi(parts[1])
			sumb += int64(parts[2]) // Update the sum of additional values

			// Add the input value to the appropriate priority queue
			if in > min {
				pqmax.Push(in)
				sumMax += int64(in)
			} else {
				pqmin.Push(in)
				sumMin += int64(in)
			}

			// Balance the two heaps if necessary
			if pqmin.Len() > pqmax.Len() {
				sumMax += int64(pqmin.Peek())
				sumMin -= int64(pqmin.Peek())
				pqmax.Push(pqmin.Pop())
			}
			if pqmin.Len() < pqmax.Len() {
				sumMax -= int64(pqmax.Peek())
				sumMin += int64(pqmax.Peek())
				pqmin.Push(pqmax.Pop())
			}

			// Update the minimum value based on the current state of the heaps
			min = pqmin.Peek()
		}
	}
}

// PriorityQueue is a min-heap for integers
type PriorityQueue struct {
	less     func(i, j int) bool
	data     []int
	swapFunc func(i, j int)
}

// Push adds an element to the priority queue
func (pq *PriorityQueue) Push(x int) {
	pq.data = append(pq.data, x)
	pq.up(len(pq.data) - 1)
}

// Pop removes and returns the minimum element from the priority queue
func (pq *PriorityQueue) Pop() int {
	n := len(pq.data) - 1
	pq.swap(0, n)
	pq.down(0, n)
	x := pq.data[n]
	pq.data = pq.data[:n]
	return x
}

// Peek returns the minimum element in the priority queue without removing it
func (pq *PriorityQueue) Peek() int {
	return pq.data[0]
}

// Len returns the number of elements in the priority queue
func (pq *PriorityQueue) Len() int {
	return len(pq.data)
}

// up moves the element at index i up the heap
func (pq *PriorityQueue) up(i int) {
	for {
		parent := (i - 1) / 2
		if i == parent || pq.less(parent, i) {
			break
		}
		pq.swap(i, parent)
		i = parent
	}
}

// down moves the element at index i down the heap
func (pq *PriorityQueue) down(i, n int) {
	for {
		child := 2*i + 1
		if child >= n {
			break
		}
		if child+1 < n && pq.less(child+1, child) {
			child++
		}
		if pq.less(i, child) {
			break
		}
		pq.swap(i, child)
		i = child
	}
}

// swap swaps the elements at indices i and j
func (pq *PriorityQueue) swap(i, j int) {
	pq.data[i], pq.data[j] = pq.data[j], pq.data[i]
}
