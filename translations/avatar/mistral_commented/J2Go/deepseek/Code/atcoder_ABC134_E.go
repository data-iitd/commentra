package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())

	m := make(map[int]int)

	for i := 0; i < n; i++ {
		scanner.Scan()
		num := parseInt(scanner.Text())

		if _, exists := m[num-1]; !exists {
			m[num]++
		} else {
			m[num-1]--
			if m[num-1] == 0 {
				delete(m, num-1)
			}
			m[num]++
		}
	}

	ans := 0

	for _, val := range m {
		ans += val
	}

	fmt.Println(ans)
}

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

