
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the input values N and P from the user
	N, P := readIntPair()

	// Define a function to calculate the number of combinations of choosing K items from a set of N items
	combi := func(N, K int) int {
		// Initialize the combination value to 1
		a := 1

		// Calculate the combination value by multiplying the number of choices from the set (N) to the current index (i)
		// and then dividing it by the current index (i+1) to account for the repetition of choices
		for i := 0; i < K; i++ {
			a *= (N - i)
			a /= (i + 1)
		}

		// Return the calculated combination value
		return a
	}

	// Initialize the answer variable to 0
	ans := 0

	// Read the input values from the user and store them in a list
	lis := readIntSlice()

	// Initialize an empty list to store the remainder of each input value when divided by 2
	ls := make([]int, 0)

	// Iterate through each value in the list and append its remainder to the list
	for _, a := range lis {
		ls = append(ls, a%2)
	}

	// Calculate the number of 1's and 0's in the list
	one := 0
	zero := 0
	for _, a := range ls {
		if a == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize two variables to store the pattern values
	pattern_a := 0
	pattern_b := 0

	// Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
	for j := 0; j <= zero; j++ {
		pattern_b += combi(zero, j)
	}

	// Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
	time := 0
	for time <= one {
		// Check if the current index (time) is a multiple of P
		if time%P == 0 {
			// If yes, add the combination value to pattern_a
			pattern_a += combi(one, time)
		}

		// Increment the index for the next combination
		time++
	}

	// Print the final answer as an integer
	fmt.Println(pattern_a * pattern_b)
}

// Function to read an integer from the user
func readInt() int {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next integer from the user
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())

	// Return the read integer
	return num
}

// Function to read a pair of integers from the user
func readIntPair() (int, int) {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next two integers from the user
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	y, _ := strconv.Atoi(scanner.Text())

	// Return the read pair of integers
	return x, y
}

// Function to read a slice of integers from the user
func readIntSlice() []int {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next line from the user
	scanner.Scan()
	text := scanner.Text()

	// Split the line into individual integers
	split := strings.Split(text, " ")

	// Convert the split strings into integers and store them in a slice
	var slice []int
	for _, num := range split {
		n, _ := strconv.Atoi(num)
		slice = append(slice, n)
	}

	// Return the read slice of integers
	return slice
}

// Function to read a string from the user
func readString() string {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next string from the user
	scanner.Scan()
	text := scanner.Text()

	// Return the read string
	return text
}

// Function to read a pair of strings from the user
func readStringPair() (string, string) {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next two strings from the user
	scanner.Scan()
	x := scanner.Text()
	scanner.Scan()
	y := scanner.Text()

	// Return the read pair of strings
	return x, y
}

// Function to read a slice of strings from the user
func readStringSlice() []string {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next line from the user
	scanner.Scan()
	text := scanner.Text()

	// Split the line into individual strings
	split := strings.Split(text, " ")

	// Return the read slice of strings
	return split
}

// Function to read a 2D grid of integers from the user
func readIntGrid(rows int) [][]int {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 2D slice to store the grid of integers
	grid := make([][]int, rows)

	// Read each row of the grid from the user
	for i := 0; i < rows; i++ {
		scanner.Scan()
		text := scanner.Text()
		split := strings.Split(text, " ")

		// Convert the split strings into integers and store them in the corresponding row of the grid
		row := make([]int, len(split))
		for j, num := range split {
			n, _ := strconv.Atoi(num)
			row[j] = n
		}
		grid[i] = row
	}

	// Return the read 2D grid of integers
	return grid
}

// Function to read a 2D grid of strings from the user
func readStringGrid(rows int) [][]string {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 2D slice to store the grid of strings
	grid := make([][]string, rows)

	// Read each row of the grid from the user
	for i := 0; i < rows; i++ {
		scanner.Scan()
		text := scanner.Text()
		split := strings.Split(text, " ")

		// Store the split strings in the corresponding row of the grid
		grid[i] = split
	}

	// Return the read 2D grid of strings
	return grid
}

// Function to read a 3D grid of integers from the user
func readIntGrid3D(rows, cols, depth int) [][][]int {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 3D slice to store the grid of integers
	grid := make([][][]int, rows)

	// Read each 2D slice of the grid from the user
	for i := 0; i < rows; i++ {
		grid[i] = make([][]int, cols)
		for j := 0; j < cols; j++ {
			scanner.Scan()
			text := scanner.Text()
			split := strings.Split(text, " ")

			// Convert the split strings into integers and store them in the corresponding 2D slice of the grid
			slice := make([]int, depth)
			for k, num := range split {
				n, _ := strconv.Atoi(num)
				slice[k] = n
			}
			grid[i][j] = slice
		}
	}

	// Return the read 3D grid of integers
	return grid
}

// Function to read a 3D grid of strings from the user
func readStringGrid3D(rows, cols, depth int) [][][]string {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 3D slice to store the grid of strings
	grid := make([][][]string, rows)

	// Read each 2D slice of the grid from the user
	for i := 0; i < rows; i++ {
		grid[i] = make([][]string, cols)
		for j := 0; j < cols; j++ {
			scanner.Scan()
			text := scanner.Text()
			split := strings.Split(text, " ")

			// Store the split strings in the corresponding 2D slice of the grid
			grid[i][j] = split
		}
	}

	// Return the read 3D grid of strings
	return grid
}

// Function to read a 4D grid of integers from the user
func readIntGrid4D(rows, cols, depth, width int) [][][][]int {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 4D slice to store the grid of integers
	grid := make([][][][]int, rows)

	// Read each 3D slice of the grid from the user
	for i := 0; i < rows; i++ {
		grid[i] = make([][][]int, cols)
		for j := 0; j < cols; j++ {
			grid[i][j] = make([][]int, depth)
			for k := 0; k < depth; k++ {
				scanner.Scan()
				text := scanner.Text()
				split := strings.Split(text, " ")

				// Convert the split strings into integers and store them in the corresponding 3D slice of the grid
				slice := make([]int, width)
				for l, num := range split {
					n, _ := strconv.Atoi(num)
					slice[l] = n
				}
				grid[i][j][k] = slice
			}
		}
	}

	// Return the read 4D grid of integers
	return grid
}

// Function to read a 4D grid of strings from the user
func readStringGrid4D(rows, cols, depth, width int) [][][][]string {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 4D slice to store the grid of strings
	grid := make([][][][]string, rows)

	// Read each 3D slice of the grid from the user
	for i := 0; i < rows; i++ {
		grid[i] = make([][][]string, cols)
		for j := 0; j < cols; j++ {
			grid[i][j] = make([][]string, depth)
			for k := 0; k < depth; k++ {
				scanner.Scan()
				text := scanner.Text()
				split := strings.Split(text, " ")

				// Store the split strings in the corresponding 3D slice of the grid
				grid[i][j][k] = split
			}
		}
	}

	// Return the read 4D grid of strings
	return grid
}

// Function to read a 5D grid of integers from the user
func readIntGrid5D(rows, cols, depth, width, height int) [][][][][]int {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a 5D slice to store the grid of integers
	grid := make([][][][][]int, rows)

	// Read each 4D slice of the grid from the user
	for i := 0; i < rows; i++ {
		grid[i] = make([][][][]int, cols)
		for j := 0; j < cols; j++ {
			grid[i][j] = make([][][]int, depth)
			for k := 0; k < depth; k++ {
				grid[i][j][k] = make([][]int, width)
				for l := 0; l < width; l++ {
					scanner.Scan()
					text := scanner.Text()
					split := strings.Split(text, " ")

					// Convert the split strings into integers and store them in the corresponding 4D slice of the grid
					slice := make([]int, height)
					for m, num := range split {
						n, _ := strconv.Atoi(num)
						slice[m] = n
					}
					grid[i][j][k][l] = slice
				}
			}
		}
	}

	// Return the read 5D grid of integers
	return grid
}

// Function to read a 5D grid of strings from the user
func readStringGrid5D(rows, cols, depth, width, height int) [][][][][]string {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	//