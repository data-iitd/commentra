

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
	for i := range allXs {
		allXs[i] = true
	}
	for i := 0; i < 12; i++ {
		if x[i]!= 'X' {
			allXs[i%columnsCount] = false
		}
	}
	for i := range allXs {
		if allXs[i] {
			return true
		}
	}
	return false
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	t, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	for i := 0; i < t; i++ {
		s := readLine(reader)
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
		fmt.Printf("%d %s\n", possibleSolutions, solutions)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), "\r\n")
	}
	return ""
}

