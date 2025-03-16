
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount)
	for i := 0; i < 12; i++ {
		if x[i]!= 'X' {
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
	t, _ := strconv.Atoi(reader.ReadLine())
	for i := 0; i < t; i++ {
		possibleSolutions := 0
		solutions := new(strings.Builder)
		s := reader.ReadLine()
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
		fmt.Println(possibleSolutions)
		fmt.Println(solutions)
	}
}

