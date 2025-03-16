
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	T := make(map[string]bool)
	for i := 0; i < n; i++ {
		com, str := readLine(reader), readLine(reader)
		if com[0] == 'i' {
			T[str] = true
		} else {
			if T[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

