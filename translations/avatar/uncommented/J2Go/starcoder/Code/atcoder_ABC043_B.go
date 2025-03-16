package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var s string
	s, _ = reader.ReadString('\n')
	s = strings.TrimSuffix(s, "\n")
	var d strings.Builder
	for _, c := range s {
		switch c {
		case '0':
			d.WriteString("0")
		case '1':
			d.WriteString("1")
		case 'B':
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1)
				d.Reset()
			}
		}
	}
	fmt.Println(d.String())
}

