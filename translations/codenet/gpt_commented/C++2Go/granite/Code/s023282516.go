
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

	divide := []string{"dream", "dreamer", "erase", "eraser"}

	can := true
	i := 0
	for i < len(S) {
		can2 := false
		for _, d := range divide {
			if strings.HasPrefix(S[i:], d) {
				can2 = true
				i += len(d)
			}
		}
		if!can2 {
			can = false
			break
		}
	}

	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
