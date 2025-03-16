
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1]
	l := make([]int, 0)
	for _, v := range strings.Split(n, " ") {
		l = append(l, int(v))
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < len(l); i++ {
		for j := i + 1; j < len(l); j++ {
			a := l[i]
			b := l[j]
			right := sort.Search(len(l), func(x int) bool { return l[x] >= a + b })
			left := sort.Search(len(l), func(x int) bool { return l[x] >= max(a-b, b-a) })
			tmp := max(0, right-left)
			if left <= i && i < right {
				tmp -= 1
			}
			if left <= j && j < right {
				tmp -= 1
			}
			ans += tmp
		}
	}
	fmt.Println(ans / 3)
}

