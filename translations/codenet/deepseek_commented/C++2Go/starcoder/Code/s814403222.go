<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"sort"
	"bufio"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
=======
type Pair struct {
	first int
	second string
}

>>>>>>> 98c87cb78a (data updated)
func main() {
	var n int
	var m int
	var a int
	var s string
<<<<<<< HEAD
	var v [22]P
	var d [33][]int
	for {
		_, err := fmt.Scanf("%d", &n)
		if err!= nil || n == 0 {
=======
	var v [22]Pair
	var d [33][]int
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
>>>>>>> 98c87cb78a (data updated)
			break
		}
		for i := 0; i < 33; i++ {
			d[i] = make([]int, 0)
		}
		for i := 0; i < n; i++ {
<<<<<<< HEAD
			v[i] = P{0, ""}
=======
			v[i].first = 0
>>>>>>> 98c87cb78a (data updated)
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
			return v[i].first < v[j].first
		})
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}

