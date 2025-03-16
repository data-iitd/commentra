
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLine().String()))
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLine().String()))
	c := make(map[int]bool)
	for i := 0; i < n; i++ {
		s := strings.TrimSpace(reader.ReadLine().String())
		for j := 0; j < m; j++ {
			if s[j] == 'S' {
				for k := j + 1; k < m; k++ {
					if s[k] == 'G' {
						c[k-j] = true
						break
					}
				}
				break
			}
		}
	}
	if len(c) == 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}
