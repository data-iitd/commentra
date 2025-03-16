package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var c [26]int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		str := scanner.Text()
		for _, char := range str {
			if 'a' <= char && char <= 'z' {
				c[char-'a']++
			} else if 'A' <= char && char <= 'Z' {
				c[char-'A']++
			}
		}
	}
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

