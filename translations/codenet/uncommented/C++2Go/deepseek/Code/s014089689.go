package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter number of characters: ")
	n, _ := reader.ReadString('\n')
	fmt.Print("Enter string: ")
	s, _ := reader.ReadString('\n')
	
	n = n[:len(n)-1] // Remove newline character
	s = s[:len(s)-1] // Remove newline character
	
	cnt := 0
	for i := 0; i < len(n); i++ {
		cnt++
		j := i + 1
		for ; j < len(n); j++ {
			if n[i] != n[j] {
				break
			}
		}
		i = j - 1
	}
	fmt.Println(cnt)
}
