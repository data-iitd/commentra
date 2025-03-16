
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s, t := "", ""
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		if s == "" {
			s = scanner.Text()
		} else {
			t = scanner.Text()
		}
	}
	s += s
	if strings.Contains(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

