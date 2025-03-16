<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		s := bufio.NewScanner(os.Stdin)
		s.Scan()
		ss := strings.Split(s.Text(), " ")
<<<<<<< HEAD
		st := make(map[string]bool)
		st[ss[0]] = true
		for j := 1; j < len(ss[0]); j++ {
			st[ss[0][j:len(ss[0])]] = true
			st[ss[0][0:j]] = true
		}
		fmt.Println(len(st))
	}
}

=======
		var st []string
		st = append(st, ss[0])
		for j := 1; j < len(ss[0]); j++ {
			var res string
			for k := 0; k < j; k++ {
				res += ss[0][k]
			}
			res = Reverse(res)
			var res2 string
			for k := j; k < len(ss[0]); k++ {
				res2 += ss[0][k]
			}
			res2 = Reverse(res2)
			var t string
			t = res + res2
			st = append(st, t)
			t = res2 + res
			st = append(st, t)
			t = res + ss[0][j:]
			st = append(st, t)
			t = ss[0][:j] + res2
			st = append(st, t)
			t = res2 + res
			st = append(st, t)
			t = res + res2
			st = append(st, t)
			t = res2 + res
			st = append(st, t)
		}
		sort.Strings(st)
		var last string
		for _, v := range st {
			if v!= last {
				fmt.Println(v)
				last = v
			}
		}
		fmt.Println()
	}
}

func Reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

>>>>>>> 98c87cb78a (data updated)
