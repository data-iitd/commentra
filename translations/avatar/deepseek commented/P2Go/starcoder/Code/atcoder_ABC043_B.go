
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	s = bufio.NewScanner(strings.NewReader(s.Text()))
	my_str := ""

	for s.Scan() {
		c := s.Text()
		if c == "0" || c == "1" {
			my_str += c
		} else if c == "B" && len(my_str)!= 0 {
			my_str = my_str[:len(my_str)-1]
		}
	}

	fmt.Println(my_str)
}

