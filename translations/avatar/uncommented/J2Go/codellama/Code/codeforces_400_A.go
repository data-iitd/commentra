
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount)
	for i := 0; i < columnsCount; i++ {
		allXs[i] = true
	}
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
	scanner := bufio.NewScanner(os.Stdin)
	t := 0
	scanner.Scan()
	t, _ = strconv.Atoi(scanner.Text())
	for i := 0; i < t; i++ {
		scanner.Scan()
		s := scanner.Text()
		possibleSolutions := 0
		solutions := ""
		if isSolution(12, s) {
			solutions += " 1x12"
			possibleSolutions++
		}
		if isSolution(6, s) {
			solutions += " 2x6"
			possibleSolutions++
		}
		if isSolution(4, s) {
			solutions += " 3x4"
			possibleSolutions++
		}
		if isSolution(3, s) {
			solutions += " 4x3"
			possibleSolutions++
		}
		if isSolution(2, s) {
			solutions += " 6x2"
			possibleSolutions++
		}
		if isSolution(1, s) {
			solutions += " 12x1"
			possibleSolutions++
		}
		fmt.Println(possibleSolutions, solutions)
	}
}

