
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	c := make([]int, 26)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		for _, r := range scanner.Text() {
			if 'a' <= r && r <= 'z' {
				c[r-'a']++
			} else if 'A' <= r && r <= 'Z' {
				c[r-'A']++
			}
		}
	}
	for i, v := range c {
		fmt.Printf("%c : %d\n", 'a'+i, v)
	}
}
