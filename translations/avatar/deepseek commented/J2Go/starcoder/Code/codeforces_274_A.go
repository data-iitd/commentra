package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	k, _ := strconv.ParseInt(readLine(reader), 10, 64)
	arr := make([]int, n)
	set := make(map[int]bool)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(readLine(reader))
	}
	sort.Ints(arr)
	count := 0
	for i := 0; i < n; i++ {
		if arr[i]%k!= 0 {
			count++
			set[arr[i]] = true
		} else if _, ok := set[arr[i]/k];!ok {
			count++
			set[arr[i]] = true
		}
	}
	fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

