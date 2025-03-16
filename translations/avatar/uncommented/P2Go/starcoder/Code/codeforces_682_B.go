package main
import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &l[i])
	}
	sort.Ints(l)
	c := 0
	for i := 0; i < n; i++ {
		if l[i] > c {
			c++
		}
	}
	fmt.Println(c + 1)
}

