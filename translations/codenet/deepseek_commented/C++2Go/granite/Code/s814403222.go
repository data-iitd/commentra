
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
	const initialSize = 22
	v := make([]pair, initialSize)
	d := make([][]int, 33)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "0" {
			break
		}
		n, _ := strconv.Atoi(text)
		for i := 0; i < 33; i++ {
			d[i] = d[i][:0]
		}
		for i := 0; i < n; i++ {
			p := strings.Split(scanner.Text(), " ")
			m, _ := strconv.Atoi(p[1])
			v[i] = pair{0, p[0]}
			for j := 0; j < m; j++ {
				a, _ := strconv.Atoi(p[j+2])
				v[i].first += n - len(d[a])
				for k := 0; k < len(d[a]); k++ {
					v[d[a][k]].first--
				}
				d[a] = append(d[a], i)
			}
		}
		sort.Slice(v, func(i, j int) bool {
			return v[i].first > v[j].first
		})
		fmt.Printf("%d %s\n", v[0].first, v[0].second)
	}
}

