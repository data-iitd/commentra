

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	myStr := ""
	for _, c := range s {
		if c == '0' || c == '1' {
			myStr += string(c)
		} else if c == 'B' && len(myStr)!= 0 {
			myStr = myStr[:len(myStr)-1]
		}
	}

	fmt.Println(myStr)
}
