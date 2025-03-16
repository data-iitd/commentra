package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()
	chars := []rune(str)
	scanner.Scan()
	k, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	n := len(chars)

	for i := 0; i < int(k); i++ {
		if chars[i] == '1' {
			if i == int(k)-1 {
				fmt.Println(1)
				return
			}
		} else {
			fmt.Println(string(chars[i]))
			return
		}
	}
}

