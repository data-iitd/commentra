
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the first string: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	fmt.Print("Enter the second string: ")
	t, _ := reader.ReadString('\n')
	t = strings.TrimSpace(t)
	hit := 0
	for i := 0; i < 3; i++ {
		if s[i] == t[i] {
			hit++
		}
	}
	fmt.Println(hit)
}

