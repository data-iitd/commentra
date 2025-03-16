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
	s := scanner.Text()
	scanner.Scan()
	t := scanner.Text()

	a := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}

	res := true

	for _, s := range a {
		sIdx := strings.Index(s, s)
		if sIdx < 0 {
			continue
		}

		t := string(t[sIdx])

		idx := 0
		for idx < len(s) {
			if strings.Index(s, s, idx) >= 0 {
				if strings.Index(s, s, idx) != strings.Index(t, t, idx) {
					res = false
					break
				} else {
					idx = strings.Index(s, s, idx) + 1
				}
			} else if strings.Index(t, t, idx) >= 0 {
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

