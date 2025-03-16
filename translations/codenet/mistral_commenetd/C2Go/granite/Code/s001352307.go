

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables i, j, t, and arrays ans and input
	var i, j, t int
	ans := make([][]int, 1024)
	input := make([][]int, 1024)
	for i = 0; i < 1024; i++ {
		ans[i] = make([]int, 2)
		input[i] = make([]int, 2)
	}

	// Loop through all test cases
	for t = 0; ; t++ {
		// Initialize all elements of arrays ans and input to zero
		for i = 0; i < 1024; i++ {
			ans[i][0] = 0
			ans[i][1] = 0
			input[i][0] = 0
			input[i][1] = 0
		}

		// Read the width W and number of blocks N from the input
		reader := bufio.NewReader(os.Stdin)
		line, _, _ := reader.ReadLine()
		data := strings.Split(string(line), " ")
		W, _ := strconv.Atoi(data[0])
		N, _ := strconv.Atoi(data[1])

		// If width W is zero, break out of the loop and move on to the next test case
		if W == 0 {
			break
		}

		// Read the dimensions of each block and store them in the input array
		for i = 0; i < N; i++ {
			line, _, _ := reader.ReadLine()
			data := strings.Split(string(line), ",")
			input[i][0], _ = strconv.Atoi(data[0])
			input[i][1], _ = strconv.Atoi(data[1])
		}

		// For each position j from the width W down to 0, update the maximum size of a rectangle that can be formed by placing a block of given size at that position
		for i = 0; i < N; i++ {
			for j = W; j >= input[i][1]; j-- {
				// If the maximum size of a rectangle that can be formed by placing a block of size input[i] at position j - input[i][1] is less than the sum of the size of the current block and the maximum size of a rectangle at position j - input[i][1], update the maximum size of a rectangle at position j
				if ans[j][0] < input[i][0]+ans[j-input[i][1]][0] {
					ans[j][0] = input[i][0] + ans[j-input[i][1]][0]
					ans[j][1] = input[i][1] + ans[j-input[i][1]][1]
				}
			}
		}

		// Find the position j such that the maximum size of a rectangle at position W - j is greater than the maximum size of a rectangle at position W - j - 1
		for j = 0; j <= W; j++ {
			if ans[W-j][0] > ans[W-j-1][0] {
				break
			}
		}

		// Print the result for the current test case
		fmt.Printf("Case %d:\n%d\n%d\n", t+1, ans[W-j][0], ans[W-j][1])
	}
}

