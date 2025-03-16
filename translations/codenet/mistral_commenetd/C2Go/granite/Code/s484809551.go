

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const (
	N_MAX = 100
	P_MAX = 100
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const patternBase = "keyence"
	var S string
	fmt.Scan(&S)

	for i := 0; i < len(patternBase); i++ {
		top := patternBase[:i]
		bottom := patternBase[i:]
		if strings.Contains(S, top) {
			if strings.HasSuffix(S, bottom) {
				if strings.Contains(S, bottom) {
					if strings.Count(S, top)+strings.Count(S, bottom)-1 <= 1 {
						fmt.Println("YES")
						return
					}
				}
			}
		}
	}
	fmt.Println("NO")
}

// 