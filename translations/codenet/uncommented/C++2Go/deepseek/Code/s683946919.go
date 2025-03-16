package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func time2min(month, day, hour, min int) int {
	const total_day_of_month = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0
	for i := 1; i < month; i++ {
		total += total_day_of_month[i-1] * 24 * 60
	}
	for i := 1; i < day; i++ {
		total += 24 * 60
	}
	total += hour*60 + min
	return total
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		N, _ := strconv.Atoi(scanner.Text())
		if N == 0 {
			break
		}

		log := make(map[int][]int)
		for i := 0; i < N; i++ {
			scanner.Scan()
			line := scanner.Text()
			parts := strings.Split(line, " ")
			dateParts := strings.Split(parts[0], "/")
			timeParts := strings.Split(parts[1], ":")
			month, _ := strconv.Atoi(dateParts[0])
			day, _ := strconv.Atoi(dateParts[1])
			hour, _ := strconv.Atoi(timeParts[0])
			minute, _ := strconv.Atoi(timeParts[1])
			id, _ := strconv.Atoi(parts[4])
			t := time2min(month, day, hour, minute)
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
			if total[id] > maxV {
				maxV = total[id]
			}
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
