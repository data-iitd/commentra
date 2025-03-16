package main

import (
	"fmt"
	"strings"
)

func main() {
	s := input()
	res := []string{}
	punctuation := []string{",", ".", "!", "?"}

	for i := 0; i < len(s); i++ {
		if i >= 1 {
			if s[i] == " " {
				if res[len(res)-1] != " " {
					res = append(res, s[i])
				} else {
					continue
				}
			} else {
				if strings.Contains(punctuation, s[i]) {
					if res[len(res)-1] == " " {
						res = res[:len(res)-1]
					}
					res = append(res, s[i])
					res = append(res, " ")
				} else {
					res = append(res, s[i])
				}
			}
		} else {
			if s[i] == " " {
				continue
			}
			if strings.Contains(punctuation, s[i]) {
				continue
			} else {
				res = append(res, s[i])
			}
		}
	}

	fmt.Println(strings.Join(res, ""))
}

func input() string {
	var s string
	fmt.Scanln(&s)
	return s
}

