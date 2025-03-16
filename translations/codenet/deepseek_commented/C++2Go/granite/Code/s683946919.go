
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		n, _ := strconv.Atoi(read(reader))
		if n == 0 {
			break
		}
		logs := make([][]int, n)
		for i := 0; i < n; i++ {
			log := strings.Split(read(reader), " ")
			month, _ := strconv.Atoi(log[0][:2])
			day, _ := strconv.Atoi(log[0][3:5])
			hour, _ := strconv.Atoi(log[1][:2])
			min, _ := strconv.Atoi(log[1][3:5])
			id, _ := strconv.Atoi(log[5])
			logs[i] = []int{month, day, hour, min, id}
		}
		total := make([]int, 1000)
		for i := 0; i < n; i++ {
			if logs[i][4] == 0 {
				continue
			}
			godStart := time2min(logs[i][0], logs[i][1], logs[i][2], logs[i][3])
			godEnd := time2min(logs[i][0], logs[i][1], logs[i][2]+1, 0)
			for j := 0; j < n; j++ {
				if logs[j][4] == 0 || i == j {
					continue
				}
				pplStart := time2min(logs[j][0], logs[j][1], logs[j][2], logs[j][3])
				pplEnd := time2min(logs[j][0], logs[j][1], logs[j][2]+1, 0)
				start := max(godStart, pplStart)
				end := min(godEnd, pplEnd)
				if start < end {
					total[logs[j][4]] += end - start
				}
			}
		}
		maxV := 0
		for i := 0; i < 1000; i++ {
			if total[i] > maxV {
				maxV = total[i]
			}
		}
		fmt.Println(maxV)
	}
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func time2min(month, day, hour, min int) int {
	total := 0
	totalDayOfMonth := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	for i := 1; i < month; i++ {
		total += totalDayOfMonth[i-1] * 24 * 60
	}
	for i := 1; i < day; i++ {
		total += 24 * 60
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

