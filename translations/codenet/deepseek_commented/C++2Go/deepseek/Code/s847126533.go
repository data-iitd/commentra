package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Function to check if it's possible to carry all books with n people and a given weight limit
func check(n, wei int, book []int) bool {
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
	in := bufio.NewScanner(os.Stdin)
	for in.Scan() {
		var m, n int
		fmt.Sscanf(in.Text(), "%d %d", &m, &n)
		if m == 0 && n == 0 {
			break
		}

		book := []int{}
		for i := 0; i < n; i++ {
			in.Scan()
			tmp := 0
			fmt.Sscanf(in.Text(), "%d", &tmp)
			book = append(book, tmp)
		}

		// Binary search to find the maximum weight a person can carry
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

