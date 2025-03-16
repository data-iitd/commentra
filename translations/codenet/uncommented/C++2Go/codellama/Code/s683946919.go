package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func time2min(month, day, hour, min int) int {
	const totalDayOfMonth = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
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
	fmt.Scan(&N)
	if N == 0 {
		return
	}

	log := make(map[int][]int)
	for i := 0; i < N; i++ {
		var month, day, hour, min, id int
		var action string
		fmt.Scan(&month, &day, &hour, &min, &action, &id)

		t := time2min(month, day, hour, min)
		log[id] = append(log[id], t)
	}

	total := make([]int, 1000)
	for i := 0; i < len(total); i++ {
		total[i] = 0
	}

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
				start := int(math.Max(float64(godStart), float64(pplStart)))
				end := int(math.Min(float64(godEnd), float64(pplEnd)))
				total[id] += int(math.Max(0, float64(end-start)))
			}
		}
	}

	maxV := 0
	for id := 0; id < 1000; id++ {
		maxV = int(math.Max(float64(total[id]), float64(maxV)))
	}
	fmt.Println(maxV)
}

