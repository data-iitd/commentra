
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(text)
	c := make([]byte, n)
	p := 97
	for i := 0; i < 4; i++ {
		for j := i; j < n; j += 4 {
			c[j] = byte(p)
			p++
		}
	}
	fmt.Println(string(c))
}

// END-OF-CODE