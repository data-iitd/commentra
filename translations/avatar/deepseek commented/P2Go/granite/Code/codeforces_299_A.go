

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
	reader.ReadString('\n')
	reader.ReadString('\n')
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	split := strings.Split(line, " ")
	var arr []int
	for _, s := range split {
		i, _ := strconv.Atoi(s)
		arr = append(arr, i)
	}
	sort.Ints(arr)
	if any(arr[0]%x == 0 for x := arr[1:])) {
		fmt.Println(arr[0])
	} else {
		fmt.Println(-1)
	}
}

// This Go code reads the input, splits the second line into a list of integers, sorts them, and checks if the smallest element is divisible by any other element in the list.
// If it is, it prints the smallest element; otherwise, it prints -1.

