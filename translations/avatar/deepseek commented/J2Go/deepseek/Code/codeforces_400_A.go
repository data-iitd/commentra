package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Method to check if there's a column filled with 'X' characters in the given string
func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount)
	for i := 0; i < len(allXs); i++ {
		allXs[i] = true
	}
	for i := 0; i < len(x); i++ {
		if x[i] != 'X' {
			allXs[i%columnsCount] = false
		}
	}
	for i := 0; i < columnsCount; i++ {
		if allXs[i] {
			return true
		}
	}
	return false
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	t, _ := reader.ReadString('\n')
	t = strings.TrimSpace(t)
	tInt := 0
	fmt.Sscanf(t, "%d", &tInt)

	for i := 0; i < tInt; i++ {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		possibleSolutions := 0
		var solutions strings.Builder

		if isSolution(12, s) {
			solutions.WriteString(" 1x12")
			possibleSolutions++
		}
		if isSolution(6, s) {
			solutions.WriteString(" 2x6")
			possibleSolutions++
		}
		if isSolution(4, s) {
			solutions.WriteString(" 3x4")
			possibleSolutions++
		}
		if isSolution(3, s) {
			solutions.WriteString(" 4x3")
			possibleSolutions++
		}
		if isSolution(2, s) {
			solutions.WriteString(" 6x2")
			possibleSolutions++
		}
		if isSolution(1, s) {
			solutions.WriteString(" 12x1")
			possibleSolutions++
		}
		fmt.Fprint(writer, possibleSolutions)
		fmt.Fprintln(writer, solutions.String())
	}
}

