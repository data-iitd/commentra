package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = str[:len(str)-1] // Remove the newline character
	c := []rune(str)
	var k int64
	fmt.Scan(&k)
	n := len(c)
	for i := 0; i < int(k); i++ {
		if c[i] == '1' {
			if i == int(k)-1 {
				fmt.Println(1)
				return
			}
		} else {
			fmt.Println(string(c[i]))
			return
		}
	}
}

