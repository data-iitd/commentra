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

	input_array := bufio.NewScanner(reader)
	input_array.Scan()
	line := input_array.Text()
	words := bufio.NewScanner(bufio.NewReader(os.Stdin))
	words.Split(bufio.ScanWords)

	var result int

	for words.Scan() {
		result++
		if words.Text() == "0" {
			break
		}
	}

	fmt.Fprintln(writer, result)
}

