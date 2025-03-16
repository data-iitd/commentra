package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values
	x, _ := strconv.Atoi(next()) // Target value
	t, _ := strconv.Atoi(next()) // Maximum number of steps
	a, _ := strconv.Atoi(next()) // Initial position of first entity
	b, _ := strconv.Atoi(next()) // Initial position of second entity
	da, _ := strconv.Atoi(next()) // Step size for first entity
	db, _ := strconv.Atoi(next()) // Step size for second entity

	first := 0 // Position of first entity after i steps
	second := 0 // Position of second entity after j steps
	ok := false // Flag to indicate if the target can be reached

	// Iterate through possible steps for the first entity
	for i := 0; i < t; i++ {
		first = a - (da * i) // Calculate position of first entity

		// Iterate through possible steps for the second entity
		for j := 0; j < t; j++ {
			second = b - (db * j) // Calculate position of second entity

			// Check if any of the conditions to reach target x are met
			if second+first == x || second == x || first == x || x == 0 {
				ok = true // Set flag to true if target is reachable
				break // Exit inner loop if target is found
			}
		}
	}

	// Output result based on whether the target can be reached
	if ok {
		fmt.Println("YES") // Target can be reached
	} else {
		fmt.Println("NO") // Target cannot be reached
	}
}

// Method to read the next integer from input
func next() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Method to read the next token from input
func nextToken() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return strings.Split(scanner.Text(), " ")[0]
}

// Method to read the next integer from input
func nextInt() int {
	i, _ := strconv.Atoi(next())
	return i
}

// Method to read the next token from input
func nextTokenInt() int {
	i, _ := strconv.Atoi(nextToken())
	return i
}

// Method to read the next line from input
func nextLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Method to read the next line from input
func nextLineInt() int {
	i, _ := strconv.Atoi(nextLine())
	return i
}

// Method to read the next line from input
func nextLineFloat() float64 {
	f, _ := strconv.ParseFloat(nextLine(), 64)
	return f
}

// Method to read the next line from input
func nextLineString() string {
	return nextLine()
}

// Method to read the next line from input
func nextLineBool() bool {
	b, _ := strconv.ParseBool(nextLine())
	return b
}

// Method to read the next line from input
func nextLineIntSlice() []int {
	s := nextLine()
	slice := make([]int, 0)
	for _, i := range strings.Split(s, " ") {
		j, _ := strconv.Atoi(i)
		slice = append(slice, j)
	}
	return slice
}

// Method to read the next line from input
func nextLineFloatSlice() []float64 {
	s := nextLine()
	slice := make([]float64, 0)
	for _, i := range strings.Split(s, " ") {
		j, _ := strconv.ParseFloat(i, 64)
		slice = append(slice, j)
	}
	return slice
}

// Method to read the next line from input
func nextLineStringSlice() []string {
	s := nextLine()
	slice := make([]string, 0)
	for _, i := range strings.Split(s, " ") {
		slice = append(slice, i)
	}
	return slice
}

// Method to read the next line from input
func nextLineBoolSlice() []bool {
	s := nextLine()
	slice := make([]bool, 0)
	for _, i := range strings.Split(s, " ") {
		j, _ := strconv.ParseBool(i)
		slice = append(slice, j)
	}
	return slice
}

// Method to read the next line from input
func nextLineIntMatrix() [][]int {
	s := nextLine()
	matrix := make([][]int, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([]int, 0)
		for _, j := range strings.Split(i, ",") {
			k, _ := strconv.Atoi(j)
			slice = append(slice, k)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineFloatMatrix() [][]float64 {
	s := nextLine()
	matrix := make([][]float64, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([]float64, 0)
		for _, j := range strings.Split(i, ",") {
			k, _ := strconv.ParseFloat(j, 64)
			slice = append(slice, k)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineStringMatrix() [][]string {
	s := nextLine()
	matrix := make([][]string, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([]string, 0)
		for _, j := range strings.Split(i, ",") {
			slice = append(slice, j)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineBoolMatrix() [][]bool {
	s := nextLine()
	matrix := make([][]bool, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([]bool, 0)
		for _, j := range strings.Split(i, ",") {
			k, _ := strconv.ParseBool(j)
			slice = append(slice, k)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineIntMatrixSlice() [][][]int {
	s := nextLine()
	matrix := make([][][]int, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][]int, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([]int, 0)
			for _, k := range strings.Split(j, "|") {
				l, _ := strconv.Atoi(k)
				slice2 = append(slice2, l)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineFloatMatrixSlice() [][][]float64 {
	s := nextLine()
	matrix := make([][][]float64, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][]float64, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([]float64, 0)
			for _, k := range strings.Split(j, "|") {
				l, _ := strconv.ParseFloat(k, 64)
				slice2 = append(slice2, l)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineStringMatrixSlice() [][][]string {
	s := nextLine()
	matrix := make([][][]string, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][]string, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([]string, 0)
			for _, k := range strings.Split(j, "|") {
				slice2 = append(slice2, k)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineBoolMatrixSlice() [][][]bool {
	s := nextLine()
	matrix := make([][][]bool, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][]bool, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([]bool, 0)
			for _, k := range strings.Split(j, "|") {
				l, _ := strconv.ParseBool(k)
				slice2 = append(slice2, l)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineIntMatrixSliceSlice() [][][][]int {
	s := nextLine()
	matrix := make([][][][]int, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][][]int, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([][]int, 0)
			for _, k := range strings.Split(j, "|") {
				slice3 := make([]int, 0)
				for _, l := range strings.Split(k, "~") {
					m, _ := strconv.Atoi(l)
					slice3 = append(slice3, m)
				}
				slice2 = append(slice2, slice3)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineFloatMatrixSliceSlice() [][][][]float64 {
	s := nextLine()
	matrix := make([][][][]float64, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][][]float64, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([][]float64, 0)
			for _, k := range strings.Split(j, "|") {
				slice3 := make([]float64, 0)
				for _, l := range strings.Split(k, "~") {
					m, _ := strconv.ParseFloat(l, 64)
					slice3 = append(slice3, m)
				}
				slice2 = append(slice2, slice3)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineStringMatrixSliceSlice() [][][][]string {
	s := nextLine()
	matrix := make([][][][]string, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][][]string, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([][]string, 0)
			for _, k := range strings.Split(j, "|") {
				slice3 := make([]string, 0)
				for _, l := range strings.Split(k, "~") {
					slice3 = append(slice3, l)
				}
				slice2 = append(slice2, slice3)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineBoolMatrixSliceSlice() [][][][]bool {
	s := nextLine()
	matrix := make([][][][]bool, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][][]bool, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([][]bool, 0)
			for _, k := range strings.Split(j, "|") {
				slice3 := make([]bool, 0)
				for _, l := range strings.Split(k, "~") {
					m, _ := strconv.ParseBool(l)
					slice3 = append(slice3, m)
				}
				slice2 = append(slice2, slice3)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return matrix
}

// Method to read the next line from input
func nextLineIntMatrixSliceSliceSlice() [][][][][]int {
	s := nextLine()
	matrix := make([][][][][]int, 0)
	for _, i := range strings.Split(s, " ") {
		slice := make([][][][]int, 0)
		for _, j := range strings.Split(i, ",") {
			slice2 := make([][][]int, 0)
			for _, k := range strings.Split(j, "|") {
				slice3 := make([][]int, 0)
				for _, l := range strings.Split(k, "~") {
					slice4 := make([]int, 0)
					for _, m := range strings.Split(l, "^") {
						n, _ := strconv.Atoi(m)
						slice4 = append(slice4, n)
					}
					slice3 = append(slice3, slice4)
				}
				slice2 = append(slice2, slice3)
			}
			slice = append(slice, slice2)
		}
		matrix = append(matrix, slice)
	}
	return m