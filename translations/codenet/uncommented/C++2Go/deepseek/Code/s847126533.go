package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(n, wei int, book []int) bool {
	tmp := wei
	n--
	for _, v := range book {
		if tmp < v {
			if n > 0 {
				n--
				tmp = wei
				if tmp < v {
					return false
				}
			} else {
				return false
			}
		}
		tmp -= v
	}
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		input := scanner.Text()
		parts := strings.Split(input, " ")
		m, _ := strconv.Atoi(parts[0])
		n, _ := strconv.Atoi(parts[1])
		if m == 0 {
			break
		}

		book := []int{}
		for i := 0; i < n; i++ {
			scanner.Scan()
			tmp, _ := strconv.Atoi(scanner.Text())
			book = append(book, tmp)
		}

		l := 0
		r := 1500000
		ans := 0
		for l < r {
			mid := (l + r) / 2
			if check(m, mid, book) {
				ans = mid
				r = mid
			} else {
				l = mid
			}
		}
		fmt.Println(ans)
	}
}

