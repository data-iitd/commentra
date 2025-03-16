
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
	h, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	w, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			t := readLine(reader)
			if t == "snuke" {
				fmt.Printf("%c%d\n", 'A'+j, i+1)
				return
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), "\r\n")
	}
	panic(err)
}

