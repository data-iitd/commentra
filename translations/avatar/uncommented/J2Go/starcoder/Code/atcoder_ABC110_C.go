package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)
	T, _ := reader.ReadString('\n')
	T = strings.TrimSpace(T)
	A := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}
	res := true
	for _, s := range A {
		sIdx := strings.Index(S, s)
		if sIdx < 0 {
			continue
		}
		t := string(T[sIdx])
		idx := 0
		for idx < len(S) {
			if strings.Index(S, s, idx) >= 0 {
				if strings.Index(S, s, idx)!= strings.Index(T, t, idx) {
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
		if!res {
			break
		}
	}
	if res {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

