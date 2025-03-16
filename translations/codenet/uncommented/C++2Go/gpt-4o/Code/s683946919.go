package main

import (
	"fmt"
	"sort"
)

func time2min(month, day, hour, min int) int {
	totalDayOfMonth := []int{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0
	for i := 1; i < month; i++ {
		total += totalDayOfMonth[i] * 24 * 60
	}
	for i := 1; i < day; i++ {
		total += 24 * 60
	}
	total += hour * 60 + min
	return total
}

func main() {
	var N int
	for {
		if _, err := fmt.Scan(&N); err != nil || N == 0 {
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

		for i := 0; i+1 < len(log[0]); i += 2 {
			godStart := log[0][i]
			godEnd := log[0][i+1]

			for id, schedule := range log {
				if id == 0 {
					continue
				}
				for j := 0; j < len(schedule); j += 2 {
					pplStart := schedule[j]
					pplEnd := schedule[j+1]
					start := max(godStart, pplStart)
					end := min(godEnd, pplEnd)
					total[id] += max(0, end-start)
				}
			}
		}

		maxV := 0
		for id := 0; id < 1000; id++ {
			maxV = max(total[id], maxV)
		}
		fmt.Println(maxV)
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

// <END-OF-CODE>
