package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount)
	for i := 0; i < 12; i++ {
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

	t := readInt(reader)
	for i := 0; i < t; i++ {
		possibleSolutions := 0
		solutions := &strings.Builder{}
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
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

func readInt(reader *bufio.Reader) int {
	numStr, _ := reader.ReadString('\n')
	numStr = strings.TrimSpace(numStr)
	num, _ := strconv.Atoi(numStr)
	return num
}

