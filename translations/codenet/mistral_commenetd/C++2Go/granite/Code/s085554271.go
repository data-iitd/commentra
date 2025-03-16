
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	k, _ := strconv.Atoi(read(reader))
	a, _ := strconv.Atoi(read(reader))
	b, _ := strconv.Atoi(read(reader))
	for i := a; i <= b; i++ {
		if i%k == 0 {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

