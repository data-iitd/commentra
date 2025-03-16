package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	res := []rune(s)
	punctuation := []rune{',', '.', '!', '?'}

	for i := 0; i < len(res); i++ {
		if i >= 1 {
			if res[i] =='' {
				if res[i-1]!='' {
					res = append(res,'')
				} else {
					continue
				}
			} else {
				if res[i] == punctuation[0] || res[i] == punctuation[1] || res[i] == punctuation[2] || res[i] == punctuation[3] {
					if res[i-1] =='' {
						res = res[:len(res)-1]
					}
					res = append(res,'')
				} else {
					res = append(res, res[i])
				}
			}
		} else {
			if res[i] =='' {
				continue
			}
			if res[i] == punctuation[0] || res[i] == punctuation[1] || res[i] == punctuation[2] || res[i] == punctuation[3] {
				continue
			} else {
				res = append(res, res[i])
			}
		}
	}

	fmt.Println(string(res))
}

