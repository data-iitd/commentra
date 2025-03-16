
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	res := []rune{}
	punctuation := ",.!?"

	for i := 0; i < len(s); i++ {
		if i > 0 {
			if s[i] =='' {
				if res[len(res)-1]!='' {
					res = append(res,'')
				}
				continue
			} else {
				if strings.ContainsRune(punctuation, s[i]) {
					if res[len(res)-1] =='' {
						res = res[:len(res)-1]
					}
					res = append(res, s[i])
					res = append(res,'')
				} else {
					res = append(res, s[i])
				}
			}
		} else {
			if s[i] =='' {
				continue
			}
			if strings.ContainsRune(punctuation, s[i]) {
				continue
			}
			res = append(res, s[i])
		}
	}

	fmt.Println(string(res))
}

