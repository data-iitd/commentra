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
	sc := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(sc.Text())
	m := make(map[int]int)
	for n > 0 {
		n--
		num, _ := strconv.Atoi(sc.Text())
		if m[num] == 0 {
			m[num] = 1
		} else {
			m[num]++
			delete(m, sort.Search(len(m), func(i int) bool { return m[i] > 1 }))
		}
	}
	ans := 0
	for _, v := range m {
		ans += v
	}
	fmt.Println(ans)
}

