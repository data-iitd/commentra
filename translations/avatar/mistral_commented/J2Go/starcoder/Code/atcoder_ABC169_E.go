
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
	var num int = 998244353
	var n int
	var ai []int
	var bi []int

	reader := bufio.NewReader(os.Stdin)
	n, _ = strconv.Atoi(strings.TrimSpace(reader.ReadString("\n")))

	for i := 0; i < n; i++ {
		st := strings.Split(strings.TrimSpace(reader.ReadString("\n")), " ")
		ai = append(ai, atoi(st[0]))
		bi = append(bi, atoi(st[1]))
	}

	sort.Ints(ai)
	sort.Ints(bi)

	if n%2 == 1 {
		fmt.Println(bi[len(bi)/2]-ai[len(ai)/2]+1)
	} else {
		b := (ai[len(ai)/2]+ai[len(ai)/2-1]+0.0)/2
		c := (bi[len(bi)/2]+bi[len(bi)/2-1]+0.0)/2
		fmt.Println(int(2*(c-b)+1))
	}
}

func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

