
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var l []int64
var limit int64 = 10000000000

func gen(number, four, seven int64) {
	if number > limit {
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
	sort.Ints64(l)
	var n int64
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	var ans int64
	for _, val := range l {
		if val >= n {
			ans = val
			break
		}
	}
	fmt.Println(ans)
}

