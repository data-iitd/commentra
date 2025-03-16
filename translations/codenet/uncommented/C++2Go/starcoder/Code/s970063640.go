package main
import (
	"fmt"
	"sort"
)
func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	var a int
	fmt.Scanf("%d\n", &a)
	var sum int
	var s [1000000]int
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &s[i])
	}
	sort.Ints(s[:n])
	for i := n - 1; i > n - a - 1; i-- {
		sum += s[i]
	}
	fmt.Printf("%d\n", sum)
}
