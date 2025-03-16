
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		var val int
		fmt.Scan(&val)
		m[val] = m[val] + 1
	}
	max := int(^uint(0) >> 1)
	for _, v := range m {
		if v > max {
			max = v
		}
	}
	fmt.Println(max, len(m))
}

