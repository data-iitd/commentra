package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func check(n int, wei int, book []int) bool {
	tmp := wei
	n--
	for i := 0; i < len(book); i++ {
		if tmp < book[i] {
			if n > 0 {
				n--
				tmp = wei
				if tmp < book[i] {
					return false
				}
			} else {
				return false
			}
		}
		tmp -= book[i]
	}
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "" {
			break
		}
		m, _ := strconv.Atoi(line)
		scanner.Scan()
		line = scanner.Text()
		n, _ := strconv.Atoi(line)
		book := make([]int, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			line = scanner.Text()
			book[i], _ = strconv.Atoi(line)
		}
		sort.Ints(book)
		l := 0
		r := 1500000
		ans := 0
		for l < r {
			mid := (l + r) / 2
			if check(m, mid, book) {
				ans = mid
				r = mid
			} else {
				l = mid + 1
			}
		}
		fmt.Println(ans)
	}
}

