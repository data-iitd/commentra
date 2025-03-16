
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	input_array := make([][]int, n)
	for i := 0; i < n; i++ {
		input_array[i] = make([]int, 4)
		input_array[i][0], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[0])
		input_array[i][1], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[1])
		input_array[i][2], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[2])
		input_array[i][3], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[3])
	}
	outdated := make([][]int, 0)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if input_array[i][0] < input_array[j][0] && input_array[i][1] < input_array[j][1] && input_array[i][2] < input_array[j][2] {
				outdated = append(outdated, input_array[i])
			}
		}
	}
	outdated = removeDuplicates(outdated)
	minimum_cost := 100000
	input_number := 0
	for i := 0; i < n; i++ {
		current_item := input_array[i]
		cost := current_item[3]
		if !contains(outdated, current_item) && cost < minimum_cost {
			minimum_cost = cost
			input_number = i + 1
		}
	}
	fmt.Println(input_number)
}

func removeDuplicates(s [][]int) [][]int {
	seen := make(map[string]bool)
	j := 0
	for _, v := range s {
		if _, ok := seen[string(v)]; !ok {
			seen[string(v)] = true
			s[j] = v
			j++
		}
	}
	return s[:j]
}

func contains(s [][]int, e []int) bool {
	for _, a := range s {
		if a[0] == e[0] && a[1] == e[1] && a[2] == e[2] && a[3] == e[3] {
			return true
		}
	}
	return false
}

