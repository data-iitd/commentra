package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	for {
		if _, err := fmt.Scanf("%d", &N); err!= nil {
			break
		}
		if N == 0 {
			break
		}
		log := make(map[int][]int)
		for i := 0; i < N; i++ {
			var month, day, hour, min, id int
			var action string
			fmt.Scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, &action, &id)
			t := time2min(month, day, hour, min)
			log[id] = append(log[id], t)
		}
		total := make([]int, 1000)
		for i := 0; i < len(log[0])-1; i += 2 {
			god_start := log[0][i]
			god_end := log[0][i+1]
			for id, schedule := range log {
				if id == 0 {
					continue
				}
				for j := 0; j < len(schedule)-1; j += 2 {
					ppl_start := schedule[j]
					ppl_end := schedule[j+1]
					start := max(god_start, ppl_start)
					end := min(god_end, ppl_end)
					total[id] += max(0, end-start)
				}
			}
		}
		max_v := 0
		for id, v := range total {
			max_v = max(max_v, v)
		}
		fmt.Println(max_v)
	}
}

func time2min(month, day, hour, min int) int {
	const total_day_of_month = [...]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0
	for i := 1; i < month; i++ {
		total += total_day_of_month[i]*24*60
	}
	for i := 1; i < day; i++ {
		total += 24*60
	}
	total += hour * 60 + min
	return total
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

