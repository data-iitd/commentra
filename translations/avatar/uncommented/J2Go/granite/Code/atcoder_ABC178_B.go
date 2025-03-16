
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
	var a [4]int64
	for i := 0; i < 4; i++ {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		a[i], _ = strconv.ParseInt(s, 10, 64)
	}
	fmt.Println(max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2]))))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// 