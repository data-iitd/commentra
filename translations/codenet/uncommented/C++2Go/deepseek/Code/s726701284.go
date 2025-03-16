package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	for i := 'a'; i <= 'z'; i++ {
		count := 0
		for _, char := range s {
			if i == char {
				count++
			}
		}
		if count == 0 {
			fmt.Println(string(i))
			break
		}
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}

