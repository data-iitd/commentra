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

	str, _ := reader.ReadString('\n')
	
	m := make(map[rune]int)
	oddCount := 0

	for _, ch := range str {
		if _, exists := m[ch]; exists {
			m[ch]++
		} else {
			m[ch] = 1
		}
	}

	for _, count := range m {
		if count % 2 != 0 {
			oddCount++
		}
	}

	if oddCount <= 1 || oddCount % 2 != 0 {
		fmt.Fprintln(writer, "First")
	} else {
		fmt.Fprintln(writer, "Second")
	}
}

