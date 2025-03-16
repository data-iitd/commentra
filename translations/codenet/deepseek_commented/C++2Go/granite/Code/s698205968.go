
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
		fields := strings.Fields(string(line))
		if len(fields)!= 3 {
			continue
		}
		m, err := strconv.Atoi(fields[0])
		if err!= nil {
			continue
		}
		f, err := strconv.Atoi(fields[1])
		if err!= nil {
			continue
		}
		r, err := strconv.Atoi(fields[2])
		if err!= nil {
			continue
		}
		if m == -1 || f == -1 {
			fmt.Println("F")
		} else if m+f >= 80 {
			fmt.Println("A")
		} else if m+f >= 65 {
			fmt.Println("B")
		} else if m+f >= 50 || r >= 50 {
			fmt.Println("C")
		} else if m+f >= 30 {
			fmt.Println("D")
		} else {
			fmt.Println("F")
		}
	}
}
