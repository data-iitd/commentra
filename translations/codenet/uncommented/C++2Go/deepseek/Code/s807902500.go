package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')
	s = s + s
	if strings.Index(s, t) >= 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
