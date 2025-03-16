
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the size of the character array: ")
	n, _ := strconv.Atoi(reader.ReadLine())

	c := make([]byte, n)

	p := byte('a')

	for i := 0; i < 4; i++ {
		for j := i; j < n; j += 4 {
			c[j] = p
			p++
		}
	}

	fmt.Println(string(c))
}

