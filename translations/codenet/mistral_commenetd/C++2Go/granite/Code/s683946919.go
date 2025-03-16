

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	const (
		total_day_of_month = 31
		max_id             = 1000
	)

	var (
		N int
		log = make([][]int, max_id)
		total = make([]int, max_id)
	)

	for {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &N)
		if N == 0 {
			break
		}

		for i := 0; i < N; i++ {
			var (
				month, day, hour, min, id int
				action string
			)
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d/%d %d:%d %s %d\n", &month, &day, &hour, &min, &action, &id)

			t := (month-1)*total_day_of_month + day - 1
			t = t*24 + hour
			t = t*60 + min

			if log[id] == nil {
				log[id] = make([]int, 0, 2)
			}
			log[id] = append(log[id], t)
		}

		for i := 0; i < max_id; i++ {
			total[i] = 0
		}

		for i := 1; i < len(log[0]); i += 2 {
			god_start := log[0][i-1]
			god_end := log[0][i]

			for j := 1; j < max_id; j++ {
				if log[j] == nil {
					continue
				}

				for k := 0; k < len(log[j]); k += 2 {
					ppl_start := log[j][k]
					ppl_end := log[j][k+1]

					start := max(god_start, ppl_start)
					end := min(god_end, ppl_end)

					if start < end {
						total[j] += end - start
					}
				}
			}
		}

		max_v := 0
		for i := 0; i < max_id; i++ {
			if max_v < total[i] {
				max_v = total[i]
			}
		}

		fmt.Println(max_v)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func str2int(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func str2ints(s string) []int {
	a := strings.Split(s, " ")
	b := make([]int, 0, len(a))
	for _, v := range a {
		b = append(b, str2int(v))
	}
	return b
}

Translate the above Go code to Python and end with comment "