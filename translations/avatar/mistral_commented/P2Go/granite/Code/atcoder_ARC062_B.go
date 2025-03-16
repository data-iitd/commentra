
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	s := strings.Split(strings.TrimSpace(readLine(reader)), "")

	numG := 0
	numP := 0
	score := 0

	for _, x := range s {
		if x == "g" {
			if numG-numP > 0 {
				score++
				numP++
			} else {
				score = score
				numG++
			}
		} else if x == "p" {
			if numG-numP > 0 {
				score = score
				numP++
			} else {
				score--
				numG++
			}
		}
	}

	fmt.Println(score)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

