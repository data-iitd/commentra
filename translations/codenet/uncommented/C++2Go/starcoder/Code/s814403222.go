package main
import (
	"fmt"
	"sort"
	"bufio"
	"os"
	"strconv"
	"strings"
)

type P struct {
	first int
	second string
}

func main() {
	var n int
	var m int
	var a int
	var s string
	var v [22]P
	var d [33][]int
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		for i := 0; i < 33; i++ {
			d[i] = make([]int, 0)
		}
		for i := 0; i < n; i++ {
			v[i].first = 0
			fmt.Scanf("%s %d", &s, &m)
			for j := 0; j < m; j++ {
				fmt.Scanf("%d", &a)
				v[i].first += n - len(d[a])
				for k := 0; k < len(d[a]); k++ {
					v[d[a][k]].first--
				}
				d[a] = append(d[a], i)
			}
		}
		sort.Slice(v[:n], func(i, j int) bool {
			return v[i].first > v[j].first
		})
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}

