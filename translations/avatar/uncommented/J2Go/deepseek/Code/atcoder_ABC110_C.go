package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	S := scanner.Text()
	scanner.Scan()
	T := scanner.Text()
	alphabet := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}
	var res bool = true
	for _, s := range alphabet {
		sIdx := strings.Index(S, s)
		if sIdx < 0 {
			continue
		}
		t := string(T[sIdx])
		idx := 0
		for idx < len(S) {
			if strings.Index(S, s, idx) >= 0 {
				if strings.Index(S, s, idx) != strings.Index(T, t, idx) {
					res = false
					break
				} else {
					idx = strings.Index(S, s, idx) + 1
				}
			} else if strings.Index(T, t, idx) >= 0 {
				res = false
				break
			} else {
				break
			}
		}
		if !res {
			break
		}
	}
	if res {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

