package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	myStr := ""
	for _, c := range input {
		if c == '0' || c == '1' {
			myStr += string(c)
		} else if c == 'B' && len(myStr) != 0 {
			myStr = myStr[:len(myStr)-1]
		}
	}
	fmt.Println(myStr)
}

