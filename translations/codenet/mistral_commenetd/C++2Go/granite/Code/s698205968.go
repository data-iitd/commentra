
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
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		parts := strings.Split(string(line), " ")
		if len(parts)!= 4 {
			continue
		}
		m, err := strconv.Atoi(parts[0])
		if err!= nil {
			continue
		}
		f, err := strconv.Atoi(parts[1])
		if err!= nil {
			continue
		}
		r, err := strconv.Atoi(parts[2])
		if err!= nil {
			continue
		}
		if m == -1 || f == -1 {
			fmt.Print("F")
			continue
		}
		if m+f >= 80 {
			fmt.Print("A")
			continue
		}
		if m+f >= 65 {
			fmt.Print("B")
			continue
		}
		if m+f >= 50 || r >= 50 {
			fmt.Print("C")
			continue
		}
		if m+f >= 30 {
			fmt.Print("D")
			continue
		}
		fmt.Print("F")
		fmt.Println()
	}
}
