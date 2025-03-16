
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	ss := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%s\n", &ss[i])
	}
	var cc string
	fmt.Fscanf(r, "%s\n", &cc)
	c := cc[0]
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	 lucky := make([]bool, len(cc))
	for j := 0; j < len(cc); j++ {
		for i := 0; i < n; i++ {
			if len(ss[i]) <= len(cc)-j {
				if strings.EqualFold(cc[j:j+len(ss[i])], ss[i]) {
					for h := 0; h < len(ss[i]); h++ {
						lucky[j+h] = true
					}
				}
			}
		}
	}
	for j := 0; j < len(cc); j++ {
		if lucky[j] {
			if strings.ToLower(string(cc[j])) == string(c) {
				if 'A' <= cc[j] && cc[j] <= 'Z' {
					cc = cc[:j] + strings.ToUpper(string(a)) + cc[j+1:]
				} else {
					cc = cc[:j] + string(a) + cc[j+1:]
				}
			} else {
				if 'A' <= cc[j] && cc[j] <= 'Z' {
					cc = cc[:j] + strings.ToUpper(string(c)) + cc[j+1:]
				} else {
					cc = cc[:j] + string(c) + cc[j+1:]
				}
			}
		}
	}
	fmt.Fprintln(w, cc)
	w.Flush()
}

