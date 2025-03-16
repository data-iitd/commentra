
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s := readString(reader)
	d := new(bytes.Buffer)
	for _, c := range s {
		switch c {
		case '0':
			d.WriteString("0")
		case '1':
			d.WriteString("1")
		case 'B':
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1)
			}
		}
	}
	fmt.Println(d.String())
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

