
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		sum := 0
		for _, c := range line {
			if c == 0x30 {
				fmt.Println(sum)
				break
			} else {
				sum += int(c - 0x30)
			}
		}
	}
}

