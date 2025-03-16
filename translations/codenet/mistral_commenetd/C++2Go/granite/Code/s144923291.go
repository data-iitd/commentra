
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Main function declaration

	reader := bufio.NewReader(os.Stdin)
	h, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	w, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	t := make([]string, h)
	for i := 0; i < h; i++ {
		t[i] = strings.TrimSpace(readLine(reader))
	}
	s := "snuke"
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if t[i][j:j+5] == s {
				fmt.Println(string('A'+j) + strconv.Itoa(i+1))
				return
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

// 