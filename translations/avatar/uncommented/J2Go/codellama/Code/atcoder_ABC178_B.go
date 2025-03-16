
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a [4]int64
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < 4; i++ {
		scanner.Scan()
		a[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	fmt.Println(max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2]))))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

