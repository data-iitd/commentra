package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	res := []rune{}
	punctuation := []rune{',', '.', '!', '?'}

	for i := 0; i < len(s); i++ {
		if i >= 1 {
			if s[i] == ' ' {
				if res[len(res)-1] != ' ' {
					res = append(res, rune(s[i]))
				} else {
					continue
				}
			} else {
				if contains(punctuation, rune(s[i])) {
					if res[len(res)-1] == ' ' {
						res = res[:len(res)-1]
					}
					res = append(res, rune(s[i]))
					res = append(res, ' ')
				} else {
					res = append(res, rune(s[i]))
				}
			}
		} else {
			if s[i] == ' ' {
				continue
			}
			if contains(punctuation, rune(s[i])) {
				continue
			} else {
				res = append(res, rune(s[i]))
			}
		}
	}

	fmt.Println(string(res))
}

func contains(slice []rune, item rune) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

