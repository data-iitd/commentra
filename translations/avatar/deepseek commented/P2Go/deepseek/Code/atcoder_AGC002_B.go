package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input from stdin
func input() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to convert a single input line to an integer
func INT() int {
	n, _ := strconv.Atoi(input())
	return n
}

// Function to read multiple integers from a single line of input
func MAP() []int {
	line := input()
	parts := strings.Split(line, " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a list of integers from a single line of input
func LIST() []int {
	line := input()
	parts := strings.Split(line, " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read multiple lines of input and return them as a list of tuples
func ZIP(n int) [][]int {
	zipped := make([][]int, n)
	for i := 0; i < n; i++ {
		zipped[i] = LIST()
	}
	return zipped
}

func main() {
	// Reading the number of balls (N) and the number of operations (M)
	N, M := MAP()[0], MAP()[1]

	// Initializing the list of balls with pairs [white pieces, red pieces]
	balls := make([][2]int, N)
	balls[0] = [2]int{0, 1}

	// Loop to process each operation
	for i := 0; i < M; i++ {
		x, y := MAP()[0]-1, MAP()[1]-1 // Reading the indices of the balls to be swapped
		w_x, r_x := balls[x][0], balls[x][1] // Extracting the current state of ball x
		w_y, r_y := balls[y][0], balls[y][1] // Extracting the current state of ball y

		// Swapping the balls if possible
		if w_x >= 1 && r_x >= 1 {
			balls[x][0] -= 1
			balls[y][1] += 1
		} else if w_x == 0 {
			balls[x][1] -= 1
			balls[y][1] += 1
		} else {
			balls[x][0] -= 1
			balls[y][0] += 1
		}
	}

	// Counting the number of balls with at least one red or white piece
	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans += 1
		}
	}

	// Printing the final count
	fmt.Println(ans)
}
