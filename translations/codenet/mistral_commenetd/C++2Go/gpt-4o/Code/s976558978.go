package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Open the input file for reading
	file, err := os.Open("dataabc155A.txt")
	if err != nil {
		file = os.Stdin
	}
	defer file.Close()

	reader := bufio.NewReader(file)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var a, b int
	fmt.Fscanf(reader, "%d\n%d\n", &a, &b)

	if a < b {
		for i := 0; i < b; i++ {
			fmt.Fprintf(writer, "%d ", a)
		}
		writer.WriteString("\n")
	} else {
		for i := 0; i < a; i++ {
			fmt.Fprintf(writer, "%d ", b)
		}
		writer.WriteString("\n")
	}
}

// <END-OF-CODE>
