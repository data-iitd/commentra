package main
import (
	"fmt"
	"math"
	"sort"
)
func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	sort.Ints(l)
	c := 0
	for i := 1; i < n; i++ {
		if l[i] > l[i-1] {
			c++
		}
	}
	fmt.Println(c + 1)
}
