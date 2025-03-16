package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	z, _ := reader.ReadString('\n')
	a := len(z) - 1
	for i := 0; i < a; i++ {
		if z[i] == z[i+1] {
			fmt.Println("Bad")
			return
		}
	}
	fmt.Println("Good")
}
