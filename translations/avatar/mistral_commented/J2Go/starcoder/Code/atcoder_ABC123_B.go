package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a := make([]int, 5)
	r := make([]int, 5)
	m := make(map[int]int)

	for i := 0; i < 5; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		r[i] = a[i] % 10
		if r[i]!= 0 {
			b := 10 - r[i]
			m[b] = a[i]
		}
	}

	ans := 0
	if len(m) == 0 {
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	last := m[len(m)-1]
	idx := 0
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i
			break
		}
	}

	for i := 0; i < 5; i++ {
		if i!= idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}

	ans += last
	fmt.Println(ans)
}

