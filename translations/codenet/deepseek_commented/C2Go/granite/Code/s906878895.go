
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
	for {
		input, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		input = strings.TrimSpace(input)
		if input == "" {
			continue
		}
		parts := strings.Split(input, " ")
		if len(parts)!= 2 {
			continue
		}
		a, err := strconv.Atoi(parts[0])
		if err!= nil {
			continue
		}
		b, err := strconv.Atoi(parts[1])
		if err!= nil {
			continue
		}
		sum := a + b
		digitCount := 0
		for sum > 0 {
			digitCount++
			sum /= 10
		}
		fmt.Println(digitCount)
	}
}

// 