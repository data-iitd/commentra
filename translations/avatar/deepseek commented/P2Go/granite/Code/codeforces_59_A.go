
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a text: ")
	txt, _ := reader.ReadString('\n')
	txt = strings.TrimSpace(txt)

	cu := 0
	cl := 0

	for _, z := range txt {
		if z >= 'a' && z <= 'z' {
			cl++
		} else {
			cu++
		}
	}

	var out string
	if cu > cl {
		out = strings.ToUpper(txt)
	} else {
		out = strings.ToLower(txt)
	}

	fmt.Println(out)
}

