package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	data := strings.Fields(input)
	num, _ := strconv.Atoi(data[0])
	k, _ := strconv.Atoi(data[1])

	input, _ = reader.ReadString('\n')
	arrStr := strings.Fields(input)
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		arr[i], _ = strconv.Atoi(arrStr[i])
	}

	sort.Ints(arr)
	different := make(map[int]bool)
	temp := 0

	for _, x := range arr {
		if x%k != 0 || !different[x/k] {
			different[x] = true
		}
		if len(different) > temp {
			temp = len(different)
		}
	}

	fmt.Println(temp)
}

