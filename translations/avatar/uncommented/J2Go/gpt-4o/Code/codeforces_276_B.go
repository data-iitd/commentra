package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	str, _ := reader.ReadString('\n')
	charCount := make(map[rune]int)
	oddCount := 0

	for _, ch := range str {
		if ch != '\n' { // Ignore the newline character
			charCount[ch]++
		}
	}

	for _, count := range charCount {
		if count%2 != 0 {
			oddCount++
		}
	}

	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Fprintln(writer, "First")
	} else {
		fmt.Fprintln(writer, "Second")
	}

	writer.Flush()
}
