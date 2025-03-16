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
	s = strings.TrimSpace(s)
	res := []string{}
	punctuation := []string{",", ".", "!", "?"}
	for i := 0; i < len(s); i++ {
		if i >= 1 {
			if string(s[i]) == "" {
				if res[len(res)-1] != "" {
					res = append(res, string(s[i]))
				} else {
					continue
				}
			} else {
				if strings.ContainsRune(strings.Join(punctuation, ""), rune(s[i])) {
					if res[len(res)-1] == "" {
						res = res[:len(res)-1]
					}
					res = append(res, string(s[i]))
					res = append(res, "")
				} else {
					res = append(res, string(s[i]))
				}
			}
		} else {
			if string(s[i]) == "" {
				continue
			}
			if strings.ContainsRune(strings.Join(punctuation, ""), rune(s[i])) {
				continue
			} else {
				res = append(res, string(s[i]))
			}
		}
	}
	fmt.Println(strings.Join(res, ""))
}

