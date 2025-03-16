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

	// Read input
	input, _ := reader.ReadString('\n')

	// Process input
	tokenizer := bufio.NewScanner(strings.NewReader(input))
	tokenizer.Split(bufio.ScanWords)

	// Output result
	fmt.Fprintln(writer, "Hello, World!")
}

