
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Function to check if it's possible to carry all books with n people and a given weight limit
func check(n int, wei int, book []int) bool {
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
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var m int
	var n int
	for scanner.Scan() {
		m = scanInt()
		if m == 0 {
			break
		}
		n = scanInt()
		book := make([]int, n)
		for i := 0; i < n; i++ {
			book[i] = scanInt()
		}
		sort.Ints(book)
		// Binary search to find the maximum weight a person can carry
		l := 0
		r := 1500000
		ans := 0
		for l < r {
			mid := (l + r) / 2
			if check(m, mid, book) {
				ans = mid
				r = mid // Adjust the right boundary
			} else {
				l = mid + 1 // Adjust the left boundary
			}
		}
		fmt.Println(ans)
	}
}

func scanInt() int {
	scanner.Scan()
	return int(scanner.Text()[0]) - '0'
}

