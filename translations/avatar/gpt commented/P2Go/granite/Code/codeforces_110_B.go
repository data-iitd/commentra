
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	 lucky := "abcd"
	s := ""

	for i := 0; i < n; i++ {
		s += string(lucky[i%4])
	}

	fmt.Println(s)
}
