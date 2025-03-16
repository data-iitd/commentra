
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var l []int64

func gen(number, four, seven int) {
	if number > 1e10 {
		return
	}
	if number > 0 && four == seven {
		l = append(l, number)
	}
	gen(number*10+4, four+1, seven)
	gen(number*10+7, four, seven+1)
}

func main() {
	gen(0, 0, 0)
	sort.Slice(l, func(i, j int) bool {
		return l[i] < l[j]
	})
	scanner := bufio.NewScanner(os.Stdin)
	var n int64
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &n)
	ans := int64(0)
	for _, val := range l {
		if val >= n {
			ans = val
			break
		}
	}
	fmt.Println(ans)
}

