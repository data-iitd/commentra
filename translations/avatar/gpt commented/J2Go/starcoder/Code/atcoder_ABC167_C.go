_
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of rows (n), columns (m), and the minimum required value (x)
	fmt.Print("Enter the number of rows (n): ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Print("Enter the number of columns (m): ")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Print("Enter the minimum required value (x): ")
	x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Initialize a 2D array to store the input values
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
	}

	// Read the values into the 2D array
	for i := 0; i < n; i++ {
		for j := 0; j <= m; j++ {
			fmt.Print("Enter a value for a[" + strconv.Itoa(i) + "][" + strconv.Itoa(j) + "]: ")
			a[i][j], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		}
	}

	// Iterate through all possible combinations of rows using bit manipulation
	min := int(^uint(0) >> 1)
	for i := 0; i < int(math.Pow(2, float64(n))); i++ {
		// Create an array to track which rows are included in the current combination
		status := make([]int, n)

		// Determine which rows are included in the current combination
		for j := 0; j < n; j++ {
			if (1 & i >> j) == 1 {
				status[j] = 1
			}
		}

		// Initialize an array to store the sum of the selected rows
		res := make([]int, m+1)

		// Calculate the sum of the selected rows
		for j := 0; j < n; j++ {
			if status[j] == 1 {
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}

		// Check if the current combination meets the minimum requirement for each column
		flag := true
		for j := 1; j <= m; j++ {
			if res[j] < x {
				flag = false
				break
			}
		}

		// If the combination is valid, update the minimum value found
		if flag {
			min = int(math.Min(float64(min), float64(res[0])))
		}
	}

	// Output the result: -1 if no valid combination was found, otherwise the minimum value
	if min == int(^uint(0) >> 1) {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}

