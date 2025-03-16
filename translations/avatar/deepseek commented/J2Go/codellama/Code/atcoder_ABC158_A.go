
package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	scanner := bufio.NewScanner(inputStream)
	writer := bufio.NewWriter(outputStream)
	solver := AStationAndBus{}
	solver.solve(1, scanner, writer)
	writer.Flush()
}

type AStationAndBus struct{}

func (solver AStationAndBus) solve(testNumber int, scanner *bufio.Scanner, writer *bufio.Writer) {
	s := scanner.Text()
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		fmt.Fprintln(writer, "Yes")
	} else {
		fmt.Fprintln(writer, "No")
	}
}

// END-OF-CODE
