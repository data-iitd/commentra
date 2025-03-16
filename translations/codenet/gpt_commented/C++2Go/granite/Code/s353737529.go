
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
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(text))

	s := ""
	if n == 0 {
		s = "0"
	} else {
		for n!= 0 {
			if n%2 == 0 {
				s = "0" + s
			} else {
				s = "1" + s
			}
			n -= abs(n%2)
			n /= -2
		}
	}

	fmt.Println(s)
}

// 