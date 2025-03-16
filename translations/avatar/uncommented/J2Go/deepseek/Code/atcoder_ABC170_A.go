package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	inputArray := bufio.NewScanner(reader)
	inputArray.Split(bufio.ScanWords)

	var result int
	for inputArray.Scan() {
		result += 1
		if inputArray.Text() == "0" {
			break
		}
	}
	fmt.Fprintln(writer, result)
}

