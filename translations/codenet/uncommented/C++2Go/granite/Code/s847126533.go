
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
		//		fmt.Printf("%d %d %d\n", n, tmp, book[i])
		tmp -= book[i]
	}
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 100000
	var m, n int
	for scanner.Scan() {
		text := scanner.Text()
		if text == "0 0" {
			break
		}
		fields := strings.Fields(text)
		m, _ = strconv.Atoi(fields[0])
		n, _ = strconv.Atoi(fields[1])
		book := make([]int, initialCapacity)
		for i := 0; i < n; i++ {
			scanner.Scan()
			book[i], _ = strconv.Atoi(scanner.Text())
		}
		l := 0
		r := 1500000
		ans := 0
		for l < r {
			if check(m, (l+r)/2, book) {
				ans = (l + r) / 2
				if r == (l+r)/2 {
					break
				}
				r = (l + r) / 2
			} else {
				if l == (l+r)/2 {
					break
				}
				l = (l + r) / 2
			}
		}
		fmt.Println(ans)
	}
}

