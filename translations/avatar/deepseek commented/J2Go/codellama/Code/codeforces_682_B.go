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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	var list []int
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		list = append(list, num)
	}
	sort.Ints(list)
	var c int = 1
	for i := 0; i < n; i++ {
		if list[i] >= c {
			c++
		}
	}
	fmt.Println(c)
}

// Debug method for debugging purposes
func debug(obj ...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

