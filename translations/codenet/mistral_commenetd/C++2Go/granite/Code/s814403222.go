

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type pair struct {
	first  int
	second string
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		if n == 0 {
			break
		}
		v := make([]pair, n)
		d := make([][]int, 33)
		for i := 0; i < n; i++ {
			v[i].first = 0
			s := strings.Split(scanner.Scan(), " ")
			m, _ := strconv.Atoi(s[1])
			for j := 0; j < m; j++ {
				a, _ := strconv.Atoi(scanner.Scan())
				v[i].first += n - len(d[a])
				for k := 0; k < len(d[a]); k++ {
					v[d[a][k]].first--
				}
				d[a] = append(d[a], i)
			}
		}
		sort.Slice(v, func(i, j int) bool {
			return v[i].first < v[j].first
		})
		fmt.Println(v[0].first, v[0].second)
	}
}
