
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()
	c := []rune(str)
	scanner.Scan()
	k, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	n := len(str)
	for i := 0; i < int(k); i++ {
		if c[i] == '1' {
			if i == int(k)-1 {
				fmt.Println(1)
				return
			}
		} else {
			fmt.Println(c[i])
			return
		}
	}
}

