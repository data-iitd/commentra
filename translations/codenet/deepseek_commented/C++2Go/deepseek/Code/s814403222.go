package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Pair struct {
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
		for i := 0; i < 33; i++ {
			d[i] = []int{}
		}
		v := make([]Pair, n)
		for i := 0; i < n; i++ {
			v[i].first = 0
			scanner.Scan()
			parts := strings.Split(scanner.Text(), " ")
			m, _ := strconv.Atoi(parts[1])
			for j := 0; j < m; j++ {
				a, _ := strconv.Atoi(parts[2+j])
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

