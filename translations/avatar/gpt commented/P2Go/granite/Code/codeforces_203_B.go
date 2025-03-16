
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the dimensions of the grid (n) and the number of operations (m)
	n, m := readTwoNums(reader)

	// Initialize a 2D slice to keep track of counts for each cell in the grid
	count := make([][]int, n)
	for i := 0; i < n; i++ {
		count[i] = make([]int, n)  // Each cell starts with a count of 0
	}

	ans := -1  // Initialize the answer variable to -1 (indicating no solution found)

	// Process each operation
	for k := 0; k < m; k++ {
		// Read the coordinates for the current operation and adjust for 0-based indexing
		x, y := readTwoNums(reader)
		x--
		y--

		found := false  // Flag to indicate if a cell has reached the count of 9

		// Iterate over the 3x3 grid centered at (x, y)
		for i := x - 2; i <= x+1; i++ {
			for j := y - 2; j <= y+1; j++ {
				// Check if the indices are within the bounds of the grid
				if i >= 0 && i < n && j >= 0 && j < n {
					count[i][j]++  // Increment the count for the current cell

					// Check if the count for this cell has reached 9
					if count[i][j] == 9 {
						found = true  // Mark that we found a cell with count 9
					}
				}
			}
		}

		// If a cell with count 9 was found, update the answer and break the loop
		if found {
			ans = k + 1  // Store the 1-based index of the operation
			break
		}
	}

	// Print the result: the operation number where a cell reached count 9, or -1 if none did
	fmt.Println(ans)
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readOneNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the dimensions of the grid (n) and the number of operations (m)
	n, m := readTwoNums(reader)

	// Initialize a 2D slice to keep track of counts for each cell in the grid
	count := make([][]int, n)
	for i := 0; i < n; i++ {
		count[i] = make([]int, n)  // Each cell starts with a count of 0
	}

	ans := -1  // Initialize the answer variable to -1 (indicating no solution found)

	// Process each operation
	for k := 0; k < m; k++ {
		// Read the coordinates for the current operation and adjust for 0-based indexing
		x, y := readTwoNums(reader)
		x--
		y--

		found := false  // Flag to indicate if a cell has reached the count of 9

		// Iterate over the 3x3 grid centered at (x, y)
		for i := x - 2; i <= x+1; i++ {
			for j := y - 2; j <= y+1; j++ {
				// Check if the indices are within the bounds of the grid
				if i >= 0 && i < n && j >= 0 && j < n {
					count[i][j]++  // Increment the count for the current cell

					// Check if the count for this cell has reached 9
					if count[i][j] == 9 {
						found = true  // Mark that we found a cell with count 9
					}
				}
			}
		}

		// If a cell with count 9 was found, update the answer and break the loop
		if found {
			ans = k + 1  // Store the 1-based index of the operation
			break
		}
	}

	// Print the result: the operation number where a cell reached count 9, or -1 if none did
	fmt.Println(ans)
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readOneNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}