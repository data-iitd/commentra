
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a int
	var z string
	fmt.Fscan(reader, &z)
	a = len(z)
	for i := 0; i < a-1; i++ {
		if z[i] == z[i+1] {
			fmt.Println("Bad")
			return
		}
	}
	fmt.Println("Good")
}

