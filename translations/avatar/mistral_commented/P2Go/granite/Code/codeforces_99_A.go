
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
	fmt.Print("Enter a string: ")
	l, _ := reader.ReadString('\n')
	l = strings.TrimSpace(l)
	l = strings.Split(l, ".")[0]
	s := strings.Split(l, "")
	last_char := s[len(s)-1]
	if last_char == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else {
		p := strings.Split(strings.Split(l, ".")[1], "")
		if int(p[0][0]) < 5 {
			fmt.Println(l)
		} else {
			s[len(s)-1] = string(int(s[len(s)-1][0]) + 1)
			fmt.Println(strings.Join(s, ""))
		}
	}
}
