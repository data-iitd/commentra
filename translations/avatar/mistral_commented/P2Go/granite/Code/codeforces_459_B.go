

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

	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	l1 := readLine(reader)
	split := strings.Split(l1, " ")

	l1_int := make([]int, n)

	for i := 0; i < n; i++ {
		temp, _ := strconv.Atoi(split[i])
		l1_int[i] = temp
	}

	min := l1_int[0]
	max := l1_int[0]

	for i := 1; i < n; i++ {
		if l1_int[i] > max {
			max = l1_int[i]
		} else if l1_int[i] < min {
			min = l1_int[i]
		}
	}

	diff := max - min

	if max == min {
		fmt.Println(diff, n*(n-1)/2)
	} else {
		max_count := 0
		min_count := 0

		for i := 0; i < n; i++ {
			if l1_int[i] == max {
				max_count++
			} else if l1_int[i] == min {
				min_count++
			}
		}

		fmt.Println(diff, max_count*min_count)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}

	return ""
}

