
package main

import (
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	s := os.Args[1]
	c := make(map[string]int)
	for _, v := range s {
		c[string(v)]++
	}
	sa := make([]string, 0, len(c))
	for k := range c {
		sa = append(sa, k)
	}
	sort.Strings(sa)
	if len(sa) != 2 {
		fmt.Println("No")
		return
	}
	for _, v := range sa {
		if c[v] != 2 {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

