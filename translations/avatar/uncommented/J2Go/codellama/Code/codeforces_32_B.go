
package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Scan()
	n := in.Text()
	s := false
	for i := 0; i < len(n); i++ {
		if n[i] == '.' {
			if s {
				fmt.Print(1)
				s = false
			} else {
				fmt.Print(0)
			}
		} else {
			if s {
				fmt.Print(2)
				s = false
			} else {
				s = true
			}
		}
	}
	in.Close()
}

