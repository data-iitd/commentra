
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	s := make([]byte, 4)
	t := make([]byte, 4)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%s", s)
	fmt.Fscanf(reader, "%s", t)
	hit := 0
	for i := 0; i < 3; i++ {
		if s[i] == t[i] {
			hit++
		}
	}
	fmt.Println(hit)
}

