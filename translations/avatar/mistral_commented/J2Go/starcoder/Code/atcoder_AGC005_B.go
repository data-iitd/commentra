
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to find the length of the left and right segments for each element
func findSegmentLength(a []int) (leftl, rightl []int) {
	// Creating an ArrayDeque object to implement a double ended queue
	que := make([]int, 0)
	// Initializing the index variable to traverse the array
	index := 0
	// Finding the length of the left and right segments for each element using two stacks
	for index < len(a) {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			// Popping the elements from the queue whose right segment length is to be calculated
			ind := que[len(que)-1]
			rightl[ind] = index - ind - 1
			que = que[:len(que)-1]
		}
		que = append(que, index)
		index++
	}
	// Calculating the length of the right segment for the last element
	for len(que) > 0 {
		ind := que[len(que)-1]
		rightl[ind] = len(a) - ind - 1
		que = que[:len(que)-1]
	}
	index = len(a) - 1
	// Finding the length of the left segments for each element using two stacks in reverse order
	for index >= 0 {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			// Popping the elements from the queue whose left segment length is to be calculated
			ind := que[len(que)-1]
			leftl[ind] = ind - index - 1
			que = que[:len(que)-1]
		}
		que = append(que, index)
		index--
	}
	// Calculating the length of the left segment for the first element
	for len(que) > 0 {
		ind := que[len(que)-1]
		leftl[ind] = ind - index - 1
		que = que[:len(que)-1]
	}
	return
}

// Function to multiply the element, left segment length, and right segment length for each element
func multiply(a, leftl, rightl []int) int {
	ans := 0
	// Calculating the answer by multiplying the element, left segment length, and right segment length for each element
	for i := 0; i < len(a); i++ {
		ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
	}
	return ans
}

func main() {
	// Reading the number of elements in the array from the console
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the array: ")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	// Creating an integer array of size N
	a := make([]int, N)
	// Reading the elements of the array from the console and storing them in the array
	fmt.Print("Enter the elements of the array: ")
	for i := 0; i < N; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	// Finding the length of the left and right segments for each element
	leftl, rightl := findSegmentLength(a)
	// Calculating the answer by multiplying the element, left segment length, and right segment length for each element
	ans := multiply(a, leftl, rightl)
	// Printing the final answer
	fmt.Println(ans)
}

