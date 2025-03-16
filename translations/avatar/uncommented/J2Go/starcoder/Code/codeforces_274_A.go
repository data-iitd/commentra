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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of k")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(arr)
	count := 0
	set := make(map[int]bool)
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

