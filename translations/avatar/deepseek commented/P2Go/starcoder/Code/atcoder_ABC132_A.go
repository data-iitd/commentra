
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	S = strings.Replace(S, "\n", "", -1)
	c := make(map[rune]int)
	for _, v := range S {
		c[v]++
	}
	Sa := make(map[rune]bool)
	for _, v := range S {
		Sa[v] = true
	}
	if len(Sa)!= 2 {
		fmt.Println("No")
		return
	}
	for _, v := range Sa {
		if c[v]!= 2 {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

