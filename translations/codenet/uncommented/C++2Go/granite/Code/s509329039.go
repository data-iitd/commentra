
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	s := make([]int, m)
	c := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Fscanf(reader, "%d %d\n", &s[i], &c[i])
		s[i]--
	}

	for i := 0; i < 1000; i++ {
		st := strconv.Itoa(i)
		if len(st)!= n {
			continue
		}
		//fmt.Println(st)
		ok := true
		for j := 0; j < m; j++ {
			if st[s[j]]!= strconv.Itoa(c[j])[0] {
				ok = false
				break
			}
		}
		if ok {
			fmt.Println(i)
			return
		}
	}
	fmt.Println(-1)
}

