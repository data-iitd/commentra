
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s, t := readTwoStrings()
	s += s
	if strings.Index(s, t)+1 > 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func readTwoStrings() (string, string) {
	scanner := bufio.NewScanner(os.Stdin)
	var s, t string
	scanner.Scan()
	s = scanner.Text()
	scanner.Scan()
	t = scanner.Text()
	return s, t
}
