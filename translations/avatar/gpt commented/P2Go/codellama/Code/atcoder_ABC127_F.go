package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of queries
	q, _ := strconv.Atoi(readLine(os.Stdin))
	// Initialize answers and sums
	ans := make([]int, 2)
	import "container/heap"

	// Initialize two heaps for managing two groups of numbers
	p1 := make([]int, 0)
	p2 := make([]int, 0)
	heap.Init(&p1)  // Create a min-heap for p1
	heap.Init(&p2)  // Create a min-heap for p2

	// Initialize sums for both heaps and a sum for additional values
	sum_b := 0
	sum_p1 := 0
	sum_p2 := 0

	// Process each query
	for i := 0; i < q; i++ {
		// Read the query line and convert it to a list of integers
		ql := readLine(os.Stdin)
		ql = strings.Split(ql, " ")
		ql = make([]int, len(ql))
		for j := 0; j < len(ql); j++ {
			ql[j], _ = strconv.Atoi(ql[j])
		}

		// If the query type is 2, perform a specific operation
		if ql[0] == 2 {
			// If both heaps are of equal length, calculate and print the result based on p2
			if len(p1) == len(p2) {
				fmt.Println(-p2[0], sum_p1 - len(p1) * -p2[0] + len(p2) * -p2[0] - sum_p2 + sum_b)
			} else {
				// If p1 is longer, calculate and print the result based on p1
				fmt.Println(p1[0], sum_p1 - len(p1) * p1[0] + len(p2) * p1[0] - sum_p2 + sum_b)
			}
		} else {
			// If the query type is 1, update the heaps and sums
			sum_b += ql[2]  // Add the third element of the query to the sum_b

			// If p1 is empty, push the new value into p1
			if len(p1) == 0 {
				heap.Push(&p1, ql[1])
				sum_p1 += ql[1]
			}
			// If the new value is greater than or equal to the smallest in p1, push it to p1
			elif p1[0] <= ql[1] {
				heap.Push(&p1, ql[1])
				sum_p1 += ql[1]
			} else {
				// Otherwise, push the negative of the new value into p2 (to maintain max-heap behavior)
				heap.Push(&p2, -ql[1])
				sum_p2 += ql[1]
			}

			// Balance the heaps if p1 has fewer elements than p2
			if len(p1) < len(p2) {
				k := heap.Pop(&p2)  // Pop the largest from p2
				heap.Push(&p1, -k)  // Push it to p1 (as positive)
				sum_p2 += k  // Update sum_p2
				sum_p1 -= k  // Update sum_p1
			}

			// Balance the heaps if p1 has more than one extra element compared to p2
			if len(p1) - 1 > len(p2) {
				k := heap.Pop(&p1)  // Pop the smallest from p1
				heap.Push(&p2, -k)  // Push it to p2 (as negative)
				sum_p1 -= k  // Update sum_p1
				sum_p2 += k  // Update sum_p2
			}
		}
	}
}

func readLine(file *os.File) <-chan string {
	out := make(chan string)
	go func() {
		in := bufio.NewReader(file)
		linePartial := ""
		for {
			bytes, isPrefix, err := in.ReadLine()
			if err != nil {
				break
			} else if isPrefix {
				linePartial += string(bytes)
			} else {
				out <- linePartial + string(bytes)
				linePartial = ""
			}
		}
		close(out)
	}()
	return out
}

// https://www.hackerrank.com/challenges/mini-max-sum/problem
