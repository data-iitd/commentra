
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
	num_inp := func() int {
		line, _ := reader.ReadString('\n')
		num, _ := strconv.Atoi(strings.TrimSpace(line))
		return num
	}
	arr_inp := func() []int {
		line, _ := reader.ReadString('\n')
		split := strings.Split(strings.TrimSpace(line), " ")
		arr := make([]int, len(split))
		for i, num := range split {
			arr[i], _ = strconv.Atoi(num)
		}
		return arr
	}
	sp_inp := func() []int {
		line, _ := reader.ReadString('\n')
		split := strings.Split(strings.TrimSpace(line), " ")
		arr := make([]int, len(split))
		for i, num := range split {
			arr[i], _ = strconv.Atoi(num)
		}
		return arr
	}
	a := sorted(map_inp(int, func() int {
		line, _ := reader.ReadString('\n')
		split := strings.Split(strings.TrimSpace(line), " ")
		return len(split) > 1
	}))
	fmt.Println([2]int{a[0], -1}[any(x%a[0] == 0 for x := range a)])
}

func sorted(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
	return arr
}

func map_inp(tp string, fn func() bool) []int {
	var arr []int
	for fn() {
		arr = append(arr, num_inp())
	}
	return arr
}

