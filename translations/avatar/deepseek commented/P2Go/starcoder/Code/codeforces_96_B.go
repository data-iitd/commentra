
package main

import "fmt"

func main() {
	l := make([]int, 0)
	limit := 10000000000
	var gen func(number, four, seven int)
	gen = func(number, four, seven int) {
		if number > limit {
			return
		}
		if number > 0 && four == seven {
			l = append(l, number)
		}
		gen(number*10+4, four+1, seven)
		gen(number*10+7, four, seven+1)
	}
	gen(0, 0, 0)
	sort.Ints(l)
	n := int(fmt.Scanf("%d\n", &n))
	ans := 0
	for _, val := range l {
		if val >= n {
			ans = val
			break
		}
	}
	fmt.Printf("%d\n", ans)
}

