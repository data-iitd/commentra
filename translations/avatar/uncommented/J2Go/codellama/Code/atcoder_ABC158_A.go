package main

import (
	"fmt"
	"os"
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

func (solver AStationAndBus) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	s := in.Text()
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		fmt.Fprintln(out, "Yes")
	} else {
		fmt.Fprintln(out, "No")
	}
}

