
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	s := strings.Split(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadLineString()), " ")
	m := make(map[string]int)
	for _, v := range s {
		m[v]++
	}
	max := 0
	var ans string
	for k, v := range m {
		if v > max {
			max = v
			ans = k
		}
	}
	fmt.Println(ans)
}

