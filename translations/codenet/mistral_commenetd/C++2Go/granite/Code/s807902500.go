

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	t := s.Text()
	s.Scan()
	s = strings.Repeat(s.Text(), 2)
	if strings.Contains(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

